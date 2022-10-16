#include <stdio.h>
#include <map>

using namespace std;

#define LIM 10000000

map<int,int> occ;

int a,b,m,r;
int pref = 22;
char s[100];
char prev[100];

int prime[3200];
int sq[10000001];

int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}

void sieve() {
    for (int i = 2; i*i <= LIM; i++) {
        int s = i*i;
        for (int j = s; j <= LIM; j+=s) {
            if (sq[j]) sq[j] = (sq[j]/gcd(s,sq[j]) * s);
            else sq[j]=s;
        }
        /*if (!prime[i]) {
            for (int j = i*i; j <= 10000000; j+=i) {
                prime[j]=1;
            }
        
            for (long long j = i*i; j <= 10000000; j*=i*i) {
                if(sq[j]) sq[i]*=j;
                else sq[i]=j;
            }
        }*/
    }
}

int main() {
    scanf("%d %d", &a, &b); 
    
    sieve();
    
    long long ans = 0;
    for (int i = a; i < a+b; i++) {
        if (sq[i]) ans += i/sq[i];
        else ans += i;
    }
    
    printf("%I64d\n", ans);
}