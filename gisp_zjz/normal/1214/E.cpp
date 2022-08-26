#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=1e6+3;
typedef pair<int,int> pi;
pi a[maxn];
vector <pi> ans;
int n,id[maxn],p[maxn],tail;
int gt(int x){
    if (x<=n) return a[x].S*2-1;
    return a[x-n].S*2;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a+1,a+n+1);reverse(a+1,a+n+1); tail=n;
    for (int i=1;i<=n;i++) p[i]=i;
    for (int i=1;i<n;i++) ans.pb((pi){i,i+1});
    for (int i=1;i<=n;i++){
        int x=i+a[i].F-1;
        if (x==tail){
            tail++;
            p[tail]=i+n;
        }
        ans.pb((pi){i+n,p[x]});
    }
    for (auto x:ans) printf("%d %d\n",gt(x.F),gt(x.S));
    return 0;
}