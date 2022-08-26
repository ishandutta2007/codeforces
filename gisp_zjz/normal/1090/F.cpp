#include<bits/stdc++.h>
#define maxn 5005
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll n,ans[maxn],d[32],k[32],r[3],p[5];
pi s[5];

ll ask(int x,int y,int z){
    cout << '?' << ' ' << x << ' ' << y << ' ' << z << endl;
    fflush(stdout);
    ll w; cin >> w;
    return w;
}

int f(int x,int y,int z){
    return (1<<x)|(1<<y)|(1<<z);
}

void solve(int x){
    memset(p,0,sizeof(p));
    for (int i=1;i<32;i++) if (d[i]==3){
        int w=0;
        for (int j=0;j<5;j++) if (i&(1<<j)) r[w++]=j;
        k[i]=ask(x+r[0],x+r[1],x+r[2]);
        for (int j=0;j<3;j++) p[r[j]]+=k[i];
    }
    for (int i=0;i<5;i++) s[i]=(pi){p[i],i};
    sort(s,s+5);
    for (int i=0;i<5;i++) p[i]=s[i].S;
    ll tot=(k[f(p[0],p[1],p[2])]+k[f(p[0],p[2],p[4])]+k[f(p[2],p[3],p[4])])/2;
    ans[x+p[0]]=tot-k[f(p[2],p[3],p[4])];
    ans[x+p[2]]=tot-k[f(p[0],p[2],p[4])];
    ans[x+p[4]]=tot-k[f(p[0],p[1],p[2])];
    ans[x+p[1]]=k[f(p[1],p[3],p[4])]-ans[x+p[4]];
    ans[x+p[3]]=k[f(p[0],p[1],p[3])]-ans[x+p[0]];
}

int main(){
    for (int i=1;i<32;i++) d[i]=d[i/2]+i%2;
    cin >> n;
    for (int i=1;i<=n/5;i++) solve(i*5-4);
    if (n%5) solve(n-4);
    cout << '!';
    for (int i=1;i<=n;i++) cout << ' ' << ans[i];
    cout << endl;
    return 0;
}