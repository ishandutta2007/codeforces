//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
    int x;
    int y;
    int w;
}a[1000000+10];
int xd,yd,zd;
int n,m,boss[100000+10];
int find(int now){
    if(boss[now]==now){
        return now;
    }
    return boss[now]=find(boss[now]);
}
bool cmp(node A,node B){
    if(A.w!=B.w)return A.w<B.w;
    return (A.x==xd&&A.y==yd&&A.w==zd)>(B.x==xd&&B.y==yd&&B.w==zd);
}
LL final;
LL lastzd;
bool solve(){
//	cout<<zd<<"*"<<xd<<" "<<yd<<" "<<" "<<lastzd<<endl;
	for(int i=1;i<=n;i++){
        boss[i]=i;
    }
    rb(i,1,m){
//    	cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].w<<endl;
    	if(a[i].x==xd&&a[i].y==yd&&a[i].w==lastzd){
			a[i].w=zd;
//			cout<<"FUFUFUFUFUUFUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"<<endl;
			break;
		}  
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
//    	cout<<
//		cout<<zd<<"*"<<a[i].x<<" "<<a[i].y<<" "<<a[i].w<<endl;
        int ue=find(a[i].x),uv=find(a[i].y);
        if(ue==uv) continue;
        
        if(a[i].x==xd&&a[i].y==yd&&a[i].w==zd) return true;
        boss[ue]=uv;
    }
    return false;
}
int main(){
//	freopen("e.out","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w); 
    }
//    if(m==45){
//    	rb(i,30,45){
//    		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].w<<endl; 
//    	}
//    }
    xd=a[1].x;
    yd=a[1].y;
    zd=a[1].w;
	lastzd=zd;
    solve();
    int now;
    rb(i,1,m){
    	if(a[i].x==xd&&a[i].y==yd&&a[i].w==zd){
    		now=i;
    		break;
    	}
    }
    int l=0,r=1000000000;
    while(r-l>10){
    	int mid=(l+r)>>1;
    	zd=mid;
		if(solve()) l=mid;
		else r=mid-1; 
		lastzd=zd;
    }
    int ANS=-INF;
    rl(i,r,l){
    	zd=i;
    	if(solve()) {
    		ANS=i;
    		break;
    	}
    	lastzd=zd;
    }
//    zd=0;
//    cout<<solve()<<endl;
    printf("%d\n",ANS);
	return 0;
}