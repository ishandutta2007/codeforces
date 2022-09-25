#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int n;
vector<ii> v[100005];
bool found[100005];
int main(){
    scanf("%d",&n);
    int a,b,c;
    for (int x=0;x<n-2;x++){
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(ii(b,c));
        v[b].push_back(ii(a,c));
        v[c].push_back(ii(a,b));
    }

    int curr;
    for (int x=1;x<=n;x++) if (v[x].size()==1) {
        curr=x;
        break;
    }

    printf("%d ",curr);
    found[curr]=true;
    if (v[v[curr][0].first].size()==2) curr=v[curr][0].first;
    else curr=v[curr][0].second;

    printf("%d ",curr);
    found[curr]=true;

    for (int x=2;x<n;x++){
        for (auto it:v[curr]){
            if (found[it.first]+found[it.second]==1){
                if (found[it.first]) curr=it.second;
                else curr=it.first;
            }
        }
        printf("%d ",curr);
        found[curr]=true;
    }
}