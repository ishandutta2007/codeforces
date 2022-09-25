#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;
int n,q;
vector<ii> ranges;
vector<ii> opt;
int decomp[200005][20];
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&q);
    int a,b;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        ranges.push_back(ii(a,b));
    }
    sort(ranges.begin(),ranges.end());
    ///sieve out any range that will never be used
    opt.push_back(ranges[0]);
    for (vector<ii>::iterator it=++ranges.begin();it!=ranges.end();it++){
        if ((*it).second>opt.back().second) opt.push_back(*it);
    }
    ///find the range that is succesor
    memset(decomp,-1,sizeof(decomp));
    int l=0,r=0; ///pointers to find succ
    while (r!=opt.size()){
        if (r+1!=opt.size() && opt[r+1].first<=opt[l].second) r++;
        else{
            if (l==r){
                r++;
            }
            else {
                decomp[l][0]=r;
            }
            l++;
        }
    }
    ///2k decomp
    for (int x=0;x<19;x++){
        for (int y=0;y<opt.size();y++){
            if (decomp[y][x]!=-1){
                decomp[y][x+1]=decomp[decomp[y][x]][x];
            }
        }
    }
    ///querying
    int m;
    int k;
    while (q--){
        scanf("%d%d",&a,&b);
        if (a<opt[0].first || opt.back().second<a){
            printf("-1\n");
            continue;
        }
        l=0,r=opt.size()-1; ///bin search to find best place to start
        while (true){
            m=(l+r)>>1;
            if (l==r) break;
            if (a<opt[m].first){
                r=m-1;
            }
            else if (opt[m+1].first<=a){
                l=m+1;
            }
            else{
                break;
            }
        }
        if (b<=opt[m].second){
            printf("1\n");
            continue;
        }
        k=2; ///intervals needed
        for (int x=18;x>=0;x--){
            if (decomp[m][x]!=-1 && opt[decomp[m][x]].second<b){
                k+=1<<x;
                m=decomp[m][x];
            }
        }
        if (decomp[m][0]==-1){
            printf("-1\n");
            continue;
        }
        m=decomp[m][0];
        if (b<=opt[m].second) printf("%d\n",k);
        else printf("-1\n");
    }
}