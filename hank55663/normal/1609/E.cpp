#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int ans,ans2;
    int Mina,Minc,Mina2,Minc2;
    int adda,addc,adda2,addc2;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),adda(0),addc(0),adda2(0),addc2(0),Mina(1e9),Minc(1e9),ans(1e9),Mina2(1e9),Minc2(1e9),ans2(1e9){

    }
}*root;
int Mina(node *n){
    return n->Mina+n->adda;
}
int Minc(node *n){
    return n->Minc+n->addc;
}
int Ans(node *n){
    return n->ans+n->adda+n->addc;
}
int Mina2(node *n){
    return n->Mina2+n->adda2;
}
int Minc2(node *n){
    return n->Minc2+n->addc2;
}
int Ans2(node *n){
    return n->ans2+n->adda2+n->addc2;
}
void pull(node *n){
    n->ans=min(Ans(n->l),min(Ans(n->r),Mina(n->l)+Minc(n->r)));
    n->ans2=min(Ans2(n->l),min(Ans2(n->r),Mina2(n->r)+Minc2(n->l)));
    //printf("%d %d %d %d\n",Ans2(n->l),Ans2(n->r),Mina(n->r),Minc2(n->l));
    //assert(n->ans2>=0);
    n->Mina=min(Mina(n->l),Mina(n->r));
    n->Minc=min(Minc(n->l),Minc(n->r));
    n->Mina2=min(Mina2(n->l),Mina2(n->r));
    n->Minc2=min(Minc2(n->l),Minc2(n->r));
}
void push(node *n){
    n->l->adda+=n->adda;
    n->r->adda+=n->adda;
    n->l->addc+=n->addc;
    n->r->addc+=n->addc;
    n->adda=0;
    n->addc=0;
    n->l->adda2+=n->adda2;
    n->r->adda2+=n->adda2;
    n->l->addc2+=n->addc2;
    n->r->addc2+=n->addc2;
    n->adda2=0;
    n->addc2=0;
}
void build(node *n,int *a,int *c,int *a2,int *c2){
    if(n->a==n->b){
        n->Mina=a[n->a];
        n->Minc=c[n->a];
        n->Mina2=a2[n->a];
        n->Minc2=c2[n->a];
        //printf("%d %d %d\n",n->a,a2[n->a],c2[n->a]);
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a,c,a2,c2);
    build(n->r,a,c,a2,c2);
    pull(n);
}
void add(node *n,int l,int r,int k,int a,int se){
    if(l>r)return;
    if(n->a>=l&&n->b<=r){
        if(a){
            if(se)n->adda2+=k;
            else
            n->adda+=k;
        }
        else{
            if(se)n->addc2+=k;
            else
            n->addc+=k;
        }
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k,a,se);
    add(n->r,l,r,k,a,se);
    pull(n);
}
void ass(node *n,int k,int w,int a,int se){
    if(n->a==n->b){
        if(a){
            if(se){
                n->Mina2=w;
                n->adda2=0;
                n->addc2=0;
            }
            else{
                n->Mina=w;
                n->adda=0;
                n->addc=0;
            }
        }
        else  if(se){
                n->Minc2=w;
                n->adda2=0;
                n->addc2=0;
            }
            else{
                n->Minc=w;
                n->adda=0;
                n->addc=0;
            }
       
        return;
    }
    int mid=(n->a+n->b)/2;
    push(n);
    if(k<=mid)ass(n->l,k,w,a,se);
    else ass(n->r,k,w,a,se);
    pull(n);
}
int S[3][1000005];
void add(int x,int k,int *s){
    for(int i = x;i<1000005;i+=i&-i){
        s[i]+=k;
    }
}
int query(int x,int *s){
    int res=0;
    for(int i =x;i>0;i-=i&-i){
        res+=s[i];
    }
    return res;
}
set<int> as,cs;
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    char cc[100005];
    scanf("%s",cc+1);
    int a[100005],c[100005],a2[100005],c2[100005];
    int cnta=0,cntb=0;
    for(int i = 1;i<=n;i++){
        a[i]=1e9;
        a2[i]=1e9;
        if(cc[i]=='a'){
            a[i]=cnta-cntb;
            a2[i]=cnta;
            cnta++;
            as.insert(i);
        }
        else if(cc[i]=='b'){
            cntb++;
        }
        add(i,1,S[cc[i]-'a']);
    }
    int cntc=0;
    cntb=0;
    for(int i = n;i>=1;i--){
        c[i]=1e9;
        c2[i]=1e9;
        if(cc[i]=='c'){
            c[i]=cntc-cntb;
            c2[i]=cntc;
            cntc++;
            cs.insert(i);
        }
        else if(cc[i]=='b'){
            cntb++;
        }
    }
    root=new node(1,n);
    build(root,a,c,a2,c2);
    cs.insert(0);
    as.insert(1e9);
    while(q--){
        int pos;
        char c;
        scanf("%d %c",&pos,&c);
        add(pos,-1,S[cc[pos]-'a']);
        if(cc[pos]=='a'){
            add(root,pos+1,n,-1,1,0);
            ass(root,pos,1e9,1,0);
             ass(root,pos,1e9,1,1);
            add(root,pos+1,n,-1,1,1);
            as.erase(pos);
            
        }
        if(cc[pos]=='c'){
            add(root,1,pos-1,-1,0,0);
            ass(root,pos,1e9,0,0);
               ass(root,pos,1e9,0,1);
            add(root,1,pos-1,-1,0,1);
            cs.erase(pos);
        }
        if(cc[pos]=='b'){
            cntb--;
            add(root,1,pos-1,1,0,0);
            add(root,pos+1,n,1,1,0);
        }
        cc[pos]=c;
        add(pos,1,S[cc[pos]-'a']);
         if(cc[pos]=='a'){
            add(root,pos+1,n,1,1,0);
            add(root,pos+1,n,1,1,1);
            int tot=query(pos-1,S[0])-query(pos-1,S[1]);
            ass(root,pos,tot,1,0);
            ass(root,pos,query(pos-1,S[0]),1,1);
            
            as.insert(pos);
        }
        if(cc[pos]=='c'){
            add(root,1,pos-1,1,0,0);
            add(root,1,pos-1,1,0,1);
            int tot=query(n,S[2])-query(pos,S[2])-query(n,S[1])+query(pos,S[1]);
            ass(root,pos,tot,0,0);
            ass(root,pos,query(n,S[2])-query(pos,S[2]),0,1);
            cs.insert(pos);
        }
        if(cc[pos]=='b'){
            cntb++;
            add(root,1,pos-1,-1,0,0);
            add(root,pos+1,n,-1,1,0);
        }
        int res=0;
        if(*cs.rbegin()<*as.begin())printf("0\n");
        else{
        printf("%d\n",res=min(min(cntb+Ans(root),(int)min(cs.size()-1,as.size()-1)),Ans2(root)));
        //printf("%d\n",Ans2(root));
        }
       /* int res2=min(cs.size()-1,as.size()-1);
        int cnta=0;
        for(auto it:as){
            if(it==1e9)
            cntc=cs.size()-1
        }*/
    }
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/