#include <cstdio>
#include <algorithm>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('') */
int main(){
	int n,d,l,i,sum1=0,sum2=0,x[100],y[100],vv=0;
	scanf("%d%d%d",&n,&d,&l);
	if(n%2==0){
		if(d>=(n-n*l)/2 && d<=(n*l-n)/2){
			if(d>=0){
				for(i=0;i<n/2;i++){
					int w=d/n;
					x[i]=2*w+1;
					y[i]=1;
				}
				vv=d%n;
				for(i=0;i<n/2;i++){
					if(vv<=l-x[i]){
						x[i]+=vv;
						goto cc;
					}else{
					vv-=l-x[i];
					x[i]=l;
					}}cc:;
			}else{
				for(i=0;i<n/2;i++){
					int w=d/n;
					y[i]=l;
					if(d%n!=0){
						x[i]=l+2*w-2;}
					else{
						x[i]=l+2*w;
					}
					if(x[i]>l){
						vv+=x[i]-l;
						x[i]=l;
					}
					if(x[i]<=0){
						vv-=1-x[i];
						x[i]=1;
					}
				}
					if(d%n!=0){
						vv+=d%n+n;}
					else{
						vv+=d%n;
					}
				for(i=0;i<n/2;i++){
					if(vv<=l-x[i]){
						x[i]+=vv;
						goto dc;
					}else{
					vv-=l-x[i];
					x[i]=l;
					}}dc:;
			}
			for(i=0;i<n/2;i++){
printf("%d %d ",x[i],y[i]);
			}
			printf("\n");
				}
		else{
				printf("-1\n");
				goto aaa;
			}}
	else{
		if(d>=(n+1-n*l+l)/2 && d<=(n*l+l+1-n)/2){		
			if(d>=0){
				for(i=0;i<(n-1)/2;i++){
					int w=d/(n-1);

					x[i]=w;
					x[i] *= 2;
					x[i]++;
					if(x[i]>l){
						vv+=x[i]-l;
						x[i]=l;
					}
					if(x[i]<=0){
						vv+=1-x[i];
						x[i]=1;
					}
					y[i]=1;
				}
				int f=n-1;
x[(n-1)/2]=d%f+vv;
if(x[(n-1)/2]>l){
	vv=x[(n-1)/2]-l;
	x[(n-1)/2]=l;
	for(i=0;i<(n-1)/2;i++){
		if(vv<=l-x[i]){
			x[i]+=vv;
			goto bb;
		}else{
			vv-=l-x[i];
			x[i]=l;
		}}
	bb:;
			}
if(x[(n-1)/2]<=0){
	if(x[0]==1 && y[0]==1){
		x[(n-1)/2]=1;
		y[0]=2;
	}}
			}else{
				for(i=0;i<(n-1)/2;i++){
					int w=d/(n-1);
					y[i]=l;
					if(d%(n-1)!=0){
						x[i]=l+2*w-2;}
					else{x[i]=l+2*w;}
				if(x[i]>l){
						vv+=x[i]-l;
						x[i]=l;
					}
					if(x[i]<=0){
						vv-=1-x[i];
						x[i]=1;
					}
				}
				if(d%(n-1)!=0){
					x[(n-1)/2]=d%(n-1)+n-1+vv;}
				else{x[(n-1)/2]=d%(n-1)+vv;}
if(x[(n-1)/2]>l){
	vv=x[(n-1)/2]-l;
	x[(n-1)/2]=l;
	for(i=0;i<(n-1)/2;i++){
		if(vv<=l-x[i]){
			x[i]+=vv;
			goto db;
		}else{
			vv-=l-x[i];
			x[i]=l;
		}}
	db:;
}
			if(x[(n-1)/2]<=0){
				vv=1-x[(n-1)/2];
	x[(n-1)/2]=1;
	for(i=0;i<(n-1)/2;i++){
		if(vv<=l-x[i]){
			x[i]-=vv;
			goto eb;
		}else{
			vv-=l-x[i];
			x[i]=l;
		}}
		eb:;
}
			}
		for(i=0;i<(n-1)/2;i++){
printf("%d %d ",x[i],y[i]);
		} printf("%d\n",x[(n-1)/2]);}
		else{
				printf("-1\n");
				goto aaa;
			}
	}
aaa:;
	return 0;
}