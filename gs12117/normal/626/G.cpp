#include<stdio.h>
#include<queue>
int n,m,q;
int p[200100];
int a[200100];
int b[200100];
struct node{
	double x;
	int loc;
	int a,b;
	bool operator<(const node&r)const{
		return x<r.x;
	}
};
std::priority_queue<node> pq;
std::priority_queue<node> mpq;
double ans;
int main(){
	int i,s,z;
	node nt,snt;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		nt.loc=i;
		nt.a=a[i];
		nt.b=b[i];
		nt.x=(double)p[i]*(b[i]+1)/(a[i]+b[i]+1)-(double)p[i]*(b[i])/(a[i]+b[i]);
		pq.push(nt);
	}
	ans=0;
	for(i=0;i<q;i++){
		scanf("%d%d",&s,&z);
		z--;
		if(s==1){
			ans+=(double)p[z]*(b[z])/(a[z]+1+b[z])-(double)p[z]*(b[z])/(a[z]+b[z]);
			a[z]++;
		}
		if(s==2){
			if(a[z]==b[z]){
				m++;
				b[z]--;
			}
			else{
				ans+=(double)p[z]*(b[z])/(a[z]-1+b[z])-(double)p[z]*(b[z])/(a[z]+b[z]);
			}
			a[z]--;
		}
		if(b[z]!=a[z]){
			nt.loc=z;
			nt.a=a[z];
			nt.b=b[z];
			nt.x=(double)p[z]*(b[z]+1)/(a[z]+b[z]+1)-(double)p[z]*(b[z])/(a[z]+b[z]);
			pq.push(nt);
		}
		if(b[z]!=0){
			nt.loc=z;
			nt.a=a[z];
			nt.b=b[z];
			nt.x=(double)p[z]*(b[z]-1)/(a[z]+b[z]-1)-(double)p[z]*(b[z])/(a[z]+b[z]);
			mpq.push(nt);
		}
		while(m>0){
			while(pq.size()>0){
				nt=pq.top();
				if(a[nt.loc]==nt.a&&b[nt.loc]==nt.b&&nt.a>nt.b)break;
				pq.pop();
			}
			if(pq.size()==0)break;
			nt=pq.top();
			pq.pop();
			m--;
			z=nt.loc;
			ans+=nt.x;
			b[z]++;
			if(b[z]!=a[z]){
				nt.loc=z;
				nt.a=a[z];
				nt.b=b[z];
				nt.x=(double)p[z]*(b[z]+1)/(a[z]+b[z]+1)-(double)p[z]*(b[z])/(a[z]+b[z]);
				pq.push(nt);
			}
			if(b[z]!=0){
				nt.loc=z;
				nt.a=a[z];
				nt.b=b[z];
				nt.x=(double)p[z]*(b[z]-1)/(a[z]+b[z]-1)-(double)p[z]*(b[z])/(a[z]+b[z]);
				mpq.push(nt);
			}
		}
		while(1){
			while(pq.size()>0){
				nt=pq.top();
				if(a[nt.loc]==nt.a&&b[nt.loc]==nt.b&&nt.a>nt.b)break;
				pq.pop();
			}
			if(pq.size()==0)break;
			while(mpq.size()>0){
				nt=mpq.top();
				if(a[nt.loc]==nt.a&&b[nt.loc]==nt.b&&nt.b>0)break;
				mpq.pop();
			}
			if(mpq.size()==0)break;
			if(pq.top().x+mpq.top().x<1e-12)break;
			ans+=pq.top().x+mpq.top().x;
			nt=pq.top();
			pq.pop();
			snt=mpq.top();
			mpq.pop();
			z=nt.loc;
			b[z]++;
			if(b[z]<a[z]){
				nt.loc=z;
				nt.a=a[z];
				nt.b=b[z];
				nt.x=(double)p[z]*(b[z]+1)/(a[z]+b[z]+1)-(double)p[z]*(b[z])/(a[z]+b[z]);
				pq.push(nt);
			}
			if(b[z]>0){
				nt.loc=z;
				nt.a=a[z];
				nt.b=b[z];
				nt.x=(double)p[z]*(b[z]-1)/(a[z]+b[z]-1)-(double)p[z]*(b[z])/(a[z]+b[z]);
				mpq.push(nt);
			}
			z=snt.loc;
			b[z]--;
			if(b[z]<a[z]){
				nt.loc=z;
				nt.a=a[z];
				nt.b=b[z];
				nt.x=(double)p[z]*(b[z]+1)/(a[z]+b[z]+1)-(double)p[z]*(b[z])/(a[z]+b[z]);
				pq.push(nt);
			}
			if(b[z]>0){
				nt.loc=z;
				nt.a=a[z];
				nt.b=b[z];
				nt.x=(double)p[z]*(b[z]-1)/(a[z]+b[z]-1)-(double)p[z]*(b[z])/(a[z]+b[z]);
				mpq.push(nt);
			}
		}
		printf("%.20lf\n",ans);
	}
}