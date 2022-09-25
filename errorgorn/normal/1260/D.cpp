#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
int m,n,k,t;
vector<int> v;
vector<iii> traps;
vector<ii> compress_ranges(vector<ii> ranges){
    vector<ii> r;
    if (ranges.empty()) return r;
    r.push_back(ranges[0]);
    for (int x=1;x<ranges.size();x++){
        if (r.back().second>=ranges[x].first){
           r.back().second=max(r.back().second,ranges[x].second);
        }
        else{
            r.push_back(ranges[x]);
        }
    }
    return r;
}

bool test(int i){
    if (i==-1) return false;
    if (i==m) return true;
    int low=v[i];

    vector<ii> ranges;

    for (int x=0;x<k;x++){
        if (traps[x].first>low) ranges.push_back(traps[x].second);
    }

    ranges=compress_ranges(ranges);

    int time=n+1;

    for (int x=0;x<ranges.size();x++){
        time+=(ranges[x].second-ranges[x].first+1)*2;
    }

    return time<=t;
}

int main(){
    scanf("%d%d%d%d",&m,&n,&k,&t);
    int temp;
    for (int x=0;x<m;x++){
        scanf("%d",&temp);
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    int a,b,c;
    for (int x=0;x<k;x++){
        scanf("%d%d%d",&a,&b,&c);
        traps.push_back(iii(c,ii(a,b)));
    }

    sort(traps.begin(),traps.end(),[](iii i,iii j){
       return i.second<j.second;
    });


    int lo=-1,hi=m,mid;
    while (hi-lo>1){
        mid=(hi+lo)>>1;
        if (test(mid)) hi=mid;
        else lo=mid;
    }

    printf("%d\n",m-hi);
}