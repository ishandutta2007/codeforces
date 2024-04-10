#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
long long s;
vector<ii> v;
vector<ii> up,low,mid;
bool test(int i){
    up.clear();
    low.clear();
    mid.clear();
    for (int x=0;x<n;x++){
        if (v[x].second<i) low.push_back(v[x]);
        else if (i<v[x].first) up.push_back(v[x]);
        else mid.push_back(v[x]);
    }

    if (low.size()>(n>>1)) return false;
    if (up.size()>(n>>1)) return false;

    long long val=0;
    int cnt=low.size();
    for (int x=0;x<low.size();x++){
        val+=low[x].first;
    }
    for (int x=0;x<mid.size();x++){
        if (cnt<(n>>1)){
            val+=mid[x].first;
            cnt++;
        }
        else val+=i;
    }
    for (int x=0;x<up.size();x++){
        val+=up[x].first;
    }

    return val<=s;
}
int main(){
    int TC;
    scanf("%d",&TC);
    int a,b,c;
    while (TC--){
        scanf("%d%lld",&n,&s);
        v.clear();
        for (int x=0;x<n;x++){
            scanf("%d%d",&a,&b);
            v.push_back(ii(a,b));
        }
        sort (v.begin(),v.end());

        a=v[(n>>1)].first,b=1000000005;
        while (a!=b){
            c=(a+b)>>1;
            if (!test(c)){
                b=c-1;
            }
            else if (test(c+1)){
                a=c+1;
            }
            else{
                a=c;
                b=c;
            }
        }
        printf("%d\n",a);
    }
}