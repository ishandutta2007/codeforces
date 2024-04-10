#include<cstdio>
#include<vector>
#define MAXN 300010
using namespace std;
vector<int> v[MAXN];
int order[MAXN],pointer[MAXN];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,type,x,i,j,notifications=0,answer=0,last=0,which;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&type,&x);
        if(type==1){
            notifications++;
            order[notifications]=x;
            answer++;
            v[x].push_back(notifications);
        }
        if(type==2){
            answer=answer-(v[x].size()-pointer[x]);
            pointer[x]=v[x].size();
        }
        if(type==3)
            if(x>last){
                for(j=last+1;j<=x;j++){
                    which=order[j];
                    if(pointer[which]!=v[which].size()&&v[which][pointer[which]]<=j){
                        answer--;
                        pointer[which]++;
                    }
                }
                last=x;
            }
        printf("%d\n",answer);
    }
    return 0;
}