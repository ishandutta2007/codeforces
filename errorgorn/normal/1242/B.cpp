#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> al[100005];
int com[100005];
vector<int> reserve;
inline vector<int> _merge(vector<int> i,vector<int> j){
    vector<int> ret;
    int it=0,jt=0;
    while (it!=i.size() || jt!=j.size()){
        if (it==i.size()) jt++;
        else if (jt==j.size()) reserve.push_back(i[it++]);
        else{
            if (i[it]==j[jt]){
                ret.push_back(i[it]);
                it++;
                jt++;
            }
            else if (i[it]>j[jt]){
                jt++;
            }
            else{
                reserve.push_back(i[it++]);
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    while (m--){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }

    for (int x=1;x<=n;x++) sort(al[x].begin(),al[x].end());

    int grp=1;
    vector<int> block;
    int temp;
    for (int x=1;x<=n;x++){
        if (com[x]) continue;

        com[x]=grp;
        block.clear();
        for (int x=1;x<=n;x++){
            if (!com[x]) block.push_back(x);
        }
        block=_merge(block,al[x]);
        while (!reserve.empty()){
            temp=reserve.back();
            reserve.pop_back();
            com[temp]=grp;
            block=_merge(block,al[temp]);
        }
        grp++;
    }

    printf("%d\n",grp-2);
}