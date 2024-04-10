#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int a[100005];
int c[100005];
vector<int> v;
int main(){
    scanf("%d%d",&n,&m);
    for (int x=0;x<n;x++) scanf("%d",&a[x]);
    for (int x=0;x<n;x++) scanf("%d",&c[x]);
    for (int x=0;x<n;x++) v.push_back(x);

    sort(v.begin(),v.end(),[](int i,int j){
        if (c[i]!=c[j]) return c[i]>c[j];
        else return i>j;
    });

    long long ans;
    int t,l;
    while (m--){
        scanf("%d%d",&t,&l);
        t--;
        if (a[t]>l){
            a[t]-=l;
            ans=(long long) c[t]*l;
        }
        else{
            l-=a[t];
            ans=(long long) a[t]*c[t];
            a[t]=0;
            while (l){
                if (v.empty()){
                    ans=0;
                    break;
                }
                //printf("proc: %d\n",v.back());
                if (a[v.back()]>l){
                    a[v.back()]-=l;
                    ans+=(long long)c[v.back()]*l;
                    l=0;
                }
                else{
                    l-=a[v.back()];
                    ans+=(long long)a[v.back()]*c[v.back()];
                    a[v.back()]=0;
                    v.pop_back();
                }
            }
        }
        printf("%lld\n",ans);
    }
}