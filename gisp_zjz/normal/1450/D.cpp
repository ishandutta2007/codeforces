#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1e6+100;
const int M=1000000007;
int _,tot[maxn],n,pos[maxn],ans[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) ans[i]=0,tot[i]=0;
        for (int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            tot[x]++; pos[x]=i;
        }
        int l=1,r=n;
        for (int i=1;i<=n;i++){
            ans[i]=tot[i]>0;
            if (tot[i]!=1) break;
            if (pos[i]==l) l++;
            else if (pos[i]==r) r--;
            else break;
        }
        bool flag=0;
        for (int i=1;i<=n;i++) flag|=tot[i]!=1;
        if (!flag) ans[n]=1;
        for (int i=n;i;i--) printf("%d",ans[i]);puts("");
    }
    return 0;
}