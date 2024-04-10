#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int p[110000];
int q[110000];
int r[110000];
int UF[402][101000];
int FIND(int a,int b){
    if(UF[a][b]<0)return b;
    return UF[a][b]=FIND(a,UF[a][b]);
}
void UNION(int a,int b,int c){
    b=FIND(a,b);
    c=FIND(a,c);
    if(b==c)return ;
    UF[a][b]+=UF[a][c];
    UF[a][c]=b;
}
int sz[110000];
int conv[110000];
vector<int>sho[110000];
int tuf[520];
pair<int,int> sm[8000000];
int S;
int Find(int a){
    if(tuf[a]<0)return a;
    return tuf[a]=Find(tuf[a]);
}
void Union(int a,int b){
    a=Find(a);b=Find(b);if(a==b)return ;
    tuf[a]+=tuf[b];tuf[b]=a;
}
int cj[600];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<b;i++){
        scanf("%d%d%d",p+i,q+i,r+i);
        p[i]--;q[i]--;r[i]--;
        sz[r[i]]++;
    }
    for(int i=0;i<402;i++)for(int j=0;j<101000;j++)UF[i][j]=-1;
    int ind=0;
    for(int i=0;i<b;i++)conv[i]=-1;
    for(int i=0;i<b;i++){
        if(sz[i]>=250){
            conv[i]=ind++;
        }
    }
    for(int i=0;i<b;i++){
        if(~conv[r[i]])UNION(conv[r[i]],p[i],q[i]);
        else sho[r[i]].push_back(i);
    }
    
    for(int i=0;i<b;i++){
        if(!sho[i].size())continue;
    //  printf("%d %d\n",i,(int)sho[i].size());
        for(int j=0;j<510;j++)tuf[j]=-1;
        map<int,int> M;
        int at=0;
        for(int j=0;j<sho[i].size();j++){
        //  printf("%d\n",sho[i][j]);
            int L,R;
            if(!M.count(p[sho[i][j]])){
                L=at;
                cj[at]=p[sho[i][j]];
                M[p[sho[i][j]]]=at;
                at++;
            }else L=M[p[sho[i][j]]];
            if(!M.count(q[sho[i][j]])){
                R=at;
                cj[at]=q[sho[i][j]];
                M[q[sho[i][j]]]=at;
                at++;
            }else R=M[q[sho[i][j]]];
            //printf("%d %d\n",L,R);
            Union(L,R);
        }
        //printf("%d\n",i);
        for(int j=0;j<at;j++)for(int k=j+1;k<at;k++){
            if(Find(j)==Find(k))sm[S++]=(make_pair(min(cj[j],cj[k]),max(cj[j],cj[k])));
        }
        //printf("%d\n",i);
    }
    std::sort(sm,sm+S);
    int c;
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        int s,t;
        scanf("%d%d",&s,&t);s--;t--;
        int ret=0;
        for(int j=0;j<ind;j++)if(FIND(j,s)==FIND(j,t))ret++;
        ret+=upper_bound(sm,sm+S,make_pair(min(s,t),max(s,t)))-lower_bound(sm,sm+S,make_pair(min(s,t),max(s,t)));
        printf("%d\n",ret);
    }
    
}