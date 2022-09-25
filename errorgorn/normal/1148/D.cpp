#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii> asc,des;
bool cmp(iii i, iii j){
    return i.first.first>j.first.first;
}
int main(){
    //freopen("input.txt","r",stdin);
    int n;
    int a,b;
    scanf("%d",&n);
    for (int x=1;x<=n;x++){
        scanf("%d%d",&a,&b);
        if (a<b){
            asc.push_back(iii(ii(a,b),x));
        }
        else{
            des.push_back(iii(ii(-a+600000,-b+600000),x));
        }
    }
    sort(asc.begin(),asc.end(),cmp);
    sort(des.begin(),des.end(),cmp);
    if (asc.size()>des.size()){
        printf("%d\n",asc.size());
        for (int x=0;x<asc.size();x++){
            printf("%d ",asc[x].second);
        }
    }
    else{
        printf("%d\n",des.size());
        for (int x=0;x<des.size();x++){
            printf("%d ",des[x].second);
        }
    }
}