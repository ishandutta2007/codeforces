#include <stdio.h>
#include <map>

using namespace std;

map<int,int> occ;

int a,b,m,r;
int pref = 22;
char s[100];
char prev[100];

int main() {
    scanf("%d %d %d %d", &a, &b ,&m, &r); 
    int curr = 0;
    
    while (occ.find(r) == occ.end()) {
        occ[r]=curr++;
        r = (r*a+b)%m;
    }
    
    printf("%d\n", curr-occ[r]);
}