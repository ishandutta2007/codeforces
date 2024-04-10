#include<bits/stdc++.h>
#define maxn 5050

using namespace std;
int n,l,r,mid;
char s[10];

bool ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    scanf("%s",s);
    return s[0]=='x';
}

int solve(){
    if (ask(0,1)) return 1;
    l=1; while (!ask(l,l*2)) l=l*2;
    r=l*2;
    while (r-l>1){
        mid=(l+r)/2;
        if (ask(l,mid)) r=mid; else l=mid;
    }
    return r;
}

int main(){
    while (true){
        scanf("%s",s);
        if (s[0]=='e') return 0;
        printf("! %d\n",solve());
        fflush(stdout);
    }
    return 0;
}