#include <cstdio>
#include <set>
#include <utility>
#include <limits>
#include <unordered_map>
using namespace std;
typedef pair<int,int> ii;
int n;
ii arr[1005];
struct line{
    int a,b,c;
    line (int _a,int _b,int _c){
        a=_a;
        b=_b;
        c=_c;
    }
    friend bool operator< (const line &i, const line &j){
        if (i.a!=j.a) return i.a<j.a;
        if (i.b!=j.b) return i.b<j.b;
        return i.c<j.c;
    }
};
set<line> s;
unordered_map<int,int> m;
int gcd(int i,int j){
    if (i>j) swap(i,j);
    while (i!=0){
        j%=i;
        swap(i,j);
    }
    return j;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int a,b,c,d;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        arr[x]=ii(a,b);
    }
    for (int x=0;x<n;x++){
        for (int y=x+1;y<n;y++){
            int a=arr[x].first-arr[y].first;
            int b=arr[y].second-arr[x].second;
            int c=arr[x].first*arr[y].second-arr[x].second*arr[y].first;
            d=gcd(abs(a),gcd(abs(b),abs(c)));
            if (a<0) d=-d;
            else if (a==0 && b<0) d=-d;
            a/=d,b/=d,c/=d;
            s.insert(*new line(a,b,c));
        }
    }
    for (set<line>::iterator it=s.begin();it!=s.end();it++){
        //printf("%d %d %d\n",(*it).a,(*it).b,(*it).c);
        m[(((*it).a+20000)<<16)+(*it).b+20000]++;
    }
    long long ans=s.size();
    ans*=ans-1;
    for (unordered_map<int,int>::iterator it=m.begin();it!=m.end();it++){
        //printf("%d\n",it->first);
        ans-=it->second*(it->second-1);
    }
    printf("%lld\n",ans>>1);
}