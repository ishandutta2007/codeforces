#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+10;
int _,n,f[maxn];
vector<int> ans;
void g(int x){
    int s=f[x]^f[x+1]^f[x+2];
    f[x]=f[x+1]=f[x+2]=s;
    ans.pb(x);
}
void work(int m){
    if (!m) return;
    if (!f[m]) work(m-1);
    else {
        if (f[m-1]) g(m-1),work(m-2);
        else if (f[m-2]) g(m-2),work(m-3);
        else g(m-2),g(m-1),work(m-2);
    }
}
int main(){
    cin >> _;
    while (_--){
        cin >> n; int s=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&f[i]);
            s^=f[i];
        }
        if (s) {puts("NO");continue;}
        ans.clear();
        if (!f[n]) work(n);
        else {
            int r=n;
            while (r>2){
                if (f[r-1]&&f[r-2]) r-=2;
                else if (f[r-1]||f[r-2]){
                    g(r-2);
                    f[r-1]=f[r-2]=f[r]=0;
                    break;
                } else {
                    g(r-2);
                    f[r-1]=f[r-2]=1;
                    r-=2;
                }
            }
            if (r<=2) {puts("NO");continue;}
            work(r);
            while (r<n) g(r),r+=2;
        }
        puts("YES");
        printf("%d\n",(int)ans.size());
        for (auto x:ans) printf("%d ",x);puts("");
    }
    return 0;
}