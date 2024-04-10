#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
struct node{
    int x;
    int y;
    int val;
    node(int _x,int _y,int _val){
        x=_x;
        y=_y;
        val=_val;
    }
};
vector<node*> nodes;
int aux(int i){
    vector<node*> curr;
    for (int x=0;x<8;x++){
        if ((1<<x)&i) curr.push_back(nodes[x]);
    }
    sort(curr.begin(),curr.end(),[](node *i, node *j){
        return i->y<j->y;
    });
    if (curr[0]->y==curr[1]->y && curr[2]->y==curr[3]->y){
        if (abs(curr[0]->x-curr[1]->x)==2){
            if (abs(curr[2]->x-curr[3]->x)!=2) return -1;
        }
        else{
            if (abs(curr[2]->x-curr[3]->x)==2) return -1;
        }
    }
    int ans=0;
    for (int x=0;x<4;x++) ans+=curr[x]->val;
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    int TC;
    scanf("%d",&TC);
    int t;
    int ans;
    while (TC--){
        nodes.clear();
        scanf("%d%d",&n,&m);
        for (int x=0;x<n;x++){
            for (int y=0;y<m;y++){
                scanf("%d",&t);
                nodes.push_back(new node(x,y,t));
            }
        }
        sort(nodes.begin(),nodes.end(),[](node *i, node *j){
            return i->val>j->val;
        });
        ans=0;
        if (n<=3){
            for (int x=0;x<n;x++){
                ans+=nodes[x]->val;
            }
        }
        else{
            if (m==1){
                for (int x=0;x<4;x++) ans+=nodes[x]->val;
            }
            else{
                for (int x=0;x<256;x++){
                    if (__builtin_popcount(x)==4){
                        ans=max(ans,aux(x));
                        //printf("%d %d\n",ans,x);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}