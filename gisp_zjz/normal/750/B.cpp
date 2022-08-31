#include<bits/stdc++.h>
#define maxn 230000

using namespace std;
int n,d,p;
char s[10];

int main(){
    cin >> n;
    while (n--){
        scanf("%d%s",&d,s);
        if (s[0]=='S') {
            if (p+d>20000) {puts("NO");return 0;}
            p+=d;
        }
        else if (s[0]=='N') {
            if (p-d<0) {puts("NO");return 0;}
            p-=d;
        }
        else if (p==0||p==20000) {puts("NO");return 0;}
    }
    if (p) puts("NO"); else puts("YES");
}