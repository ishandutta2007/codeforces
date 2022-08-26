#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pi;
const int maxn=4444;
int _,n,a[maxn];
vi ans;
int fp(int x){
    for (int i=1;i<=n;i++) if (a[i]==x) return i;
    return -1;
}
void work(int x){
    ans.pb(x);
    reverse(a+1,a+x+1);
}
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        bool flag=0;
        for (int i=1;i<=n;i++) if ((a[i]-i)&1) flag=1;
        if (flag){puts("-1");continue;}
        ans.clear();
        for (int i=n/2;i;i--){
            work(fp(i*2+1));
            work(fp(i*2)-1);
            work(fp(i*2)+1);
            work(fp(i*2+1));
            assert(a[2]==i*2);
            work(i*2+1);
        }
        printf("%d\n",ans.size());
        for (auto x:ans) printf("%d ",x);puts("");
    }
}