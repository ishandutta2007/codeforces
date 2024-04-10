#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int n,m,f[505],a[505],now,last;
pi b[505];
int ask0(int x){
    printf("? ");
    for (int i=1;i<=m;i++) printf("%d",i==x);
    puts(""); fflush(stdout);
    int ret; scanf("%d",&ret);
    return ret;
}
int ask(){
    printf("? ");
    for (int i=1;i<=m;i++) printf("%d",f[i]);
    puts(""); fflush(stdout);
    int ret; scanf("%d",&ret);
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=m;i++) a[i]=ask0(i),f[i]=1,b[i]=(pi){-a[i],i};
    sort(b+1,b+m+1);
    last=ask();
    for (int i=1;i<m;i++){
        int p=b[i].S;
        f[p]=0; now=ask();
        if (last==now){
            last=now;
            continue;
        } else if (last==now+a[p]){
            f[p]=1;
        } else {
            last=now;
        }
    }
    printf("! %d\n",last);
    return 0;
}