#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
int n,pos;
bool ans;
struct node{
	int a,b,c,d;
}q[100002]; 
inline bool cmp(re node x,re node y){
	return (x.a==y.a)?x.c<y.c:x.a<y.a;
}
inline bool pd(re int a1,re int b1,re int a2,re int b2){
	return max(a1,a2)<=min(b1,b2); 
}
int main(){
n=read();
srand((unsigned)time(NULL));
for(re int i=1;i<=n;++i){
	q[i].a=read();
	q[i].b=read();
	q[i].c=read();
	q[i].d=read();
 
}
sort(q+1,q+n+1,cmp);
for(re int i=1;i<=n;++i){
	for(re int j=1;j<=300;++j){
		pos=(rand()%n)+1;
		if(pd(q[i].a,q[i].b,q[j].a,q[j].b)^pd(q[i].c,q[i].d,q[j].c,q[j].d)){
			puts("NO");
			return 0;
		}
	}
	for(re int j=i+1;j<=min(i+300,n);++j)
	if(pd(q[i].a,q[i].b,q[j].a,q[j].b)^pd(q[i].c,q[i].d,q[j].c,q[j].d)){
			puts("NO");
			return 0;
		}
	for(re int j=max(i+1,n-300);j<=n;++j)if(pd(q[i].a,q[i].b,q[j].a,q[j].b)^pd(q[i].c,q[i].d,q[j].c,q[j].d)){
			puts("NO");
			return 0;
		}
}
 
puts("YES");
}