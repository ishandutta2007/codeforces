#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int vc[101];
char s[20];
struct block{int p,l,n,pp;};
block v[101];
bool cmp1(block a,block b){
    if(a.p<b.p)
        return true;
    else
        return false;
}
bool cmp2(block a,block b){
    if(a.n<b.n)
        return true;
    else
        return false;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,t,q,nr,i,p,l,pp,b=0,r=0;
    scanf("%d%d",&t,&n);
    for(q=1;q<=t;q++){
        scanf("%s",&s);
        if(strcmp(s,"alloc")==0){
            scanf("%d",&nr);
            i=1;
            l=0;
            pp=0;
            while(l<nr&&i<=n){
                if(vc[i]==0){
                    if(pp==0){
                        pp=1;
                        p=i;
                    }
                    l++;
                }
                else{
                    l=0;
                    pp=0;
                }
                i++;
            }
            if(l<nr)
                printf("NULL\n");
            else{
                for(i=p;i<=p+nr-1;i++)
                    vc[i]=1;
                b++;
                v[b].p=p;
                v[b].l=nr;
                printf("%d\n",b);
                r+=nr;
                v[b].n=b;
            }
        }
        if(strcmp(s,"erase")==0){
            scanf("%d",&nr);
            if(nr>b||nr<1||v[nr].pp==1)
                printf("ILLEGAL_ERASE_ARGUMENT\n");
            else{
                for(i=v[nr].p;i<=v[nr].p+v[nr].l-1;i++)
                    vc[i]=0;
                r-=v[nr].l;
                v[nr].pp=1;
                v[nr].l=0;
                v[nr].p=99999;
            }
        }
        if(strcmp(s,"defragment")==0){
            for(i=1;i<=r;i++)
                vc[i]=1;
            for(i=r+1;i<=n;i++)
                vc[i]=0;
            sort(v+1,v+b+1,cmp1);
            nr=1;
            for(i=1;i<=b;i++)
                if(v[i].pp==0){
                    v[i].p=nr;
                    nr+=v[i].l;
                }
            sort(v+1,v+b+1,cmp2);
        }
    }
    return 0;
}