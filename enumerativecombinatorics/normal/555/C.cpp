#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
int row[210000];
int col[210000];
char dir[210000];
int segtree[2][524288];
int z[210000];
set<pair<int,char> > S;
void update(int a,int b,int c,int d,int e,int t,int to){
    if(d<a||b<c)return ;
    if(c<=a&&b<=d){
        segtree[t][e]=max(segtree[t][e],to);return;
    }
    update(a,(a+b)/2,c,d,e*2,t,to);
    update((a+b)/2+1,b,c,d,e*2+1,t,to);
}
int query(int t,int at){
    int ret=0;
    at+=262144;
    while(at){
        ret=max(segtree[t][at],ret);
        at/=2;
    }
    return ret;
}
int main(){
    int a,b;scanf("%d%d",&a,&b);
    for(int i=0;i<b;i++){
        scanf("%d%d%s",col+i,row+i,dir+i);
        row[i]--;col[i]--;
        z[i]=col[i];
    }
    std::sort(z,z+b);
    for(int i=0;i<b;i++){
        if(S.count(make_pair(col[i],dir[i]))){
            printf("0\n");continue;
        }
        S.insert(make_pair(col[i],dir[i]));
        int at=lower_bound(z,z+b,col[i])-z;
        if(dir[i]=='U'){
            int to=query(0,at);
            printf("%d\n",row[i]+1-to);
            int tmp=lower_bound(z,z+b,a-to)-z;
            update(0,262143,at,tmp,1,1,col[i]+1);
        }else{
            int to=query(1,at);
            printf("%d\n",col[i]+1-to);
            int tmp=lower_bound(z,z+b,to-1)-z;
            update(0,262143,tmp,at,1,0,row[i]+1);
        }
    }
}