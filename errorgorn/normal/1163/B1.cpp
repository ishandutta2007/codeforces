#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int n;
int items[100005];
multiset<int> s;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int t;
    int ans=0;
    for (int x=1;x<=n;x++){
        scanf("%d",&t);
        if (items[t]){
            s.erase(s.find(items[t]));
        }
        items[t]++;
        s.insert(items[t]);
        if (s.size()==1 || (*s.begin()==1 && *(++s.begin())==*(s.rbegin()))||((*s.rbegin()==*(++s.rbegin())+1) && *(s.begin())==*(++s.rbegin()))){
            ans=max(ans,x);
        }
    }
    printf("%d\n",ans);
}