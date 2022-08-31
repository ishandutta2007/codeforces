#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int m,n,o,t;
bool f[35];

int qry(int x){
    printf("%d\n",x);
    fflush(stdout);
    scanf("%d",&o);
    if (!o) exit(0);
    return o;
}

void ask(int l,int r,int p){
    if (l==r) t=qry(l);
    int mid=(l+r)/2;
    t=qry(mid);
    if (!f[p%n]) t=-t;
    if (t==1) ask(l,mid-1,p+1); else ask(mid+1,r,p+1);
}

int main(){
    cin >> m >> n;
    for (int i=0;i<n;i++){
        t=qry(1);
        if (t==-1) f[i]=1; else f[i]=0;
    }
    ask(1,m,0);
}