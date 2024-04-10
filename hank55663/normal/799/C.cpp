//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 10005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
struct clo{
	int f,b,p,i;
};
bool operator>(const clo &a,const clo &b){
	return a.p>b.p;
} 
int main() {
	int n,c,d;
	scanf("%d %d %d",&n,&c,&d);
	pair<int,int> pd[100005],pc[100005];
	int dd=0,ccc=0;
	for(int i=0;i<n;i++){
		int a,b;
		char cc;
		scanf("%d %d %c",&a,&b,&cc);
		if(cc=='D')
		pd[dd++]=mp(a,b);
		else
		pc[ccc++]=mp(a,b);
	}
	sort(pd,pd+dd);
	sort(pc,pc+ccc);
	int ans=0;
	for(int i=dd-1;i>=0;i--)
		if(pd[i].y<=d){
			ans+=pd[i].x;
			break;
		}
	for(int i=ccc-1;i>=0&&ans!=0;i--){
		if(pc[i].y<=c){
			ans+=pc[i].x;
			break;
		}
		if(i==0)
		ans=0;
	}
	//printf("%d\n",ans);
	for(int i=0;i<dd;i++){
		swap(pd[i].x,pd[i].y);
	}
	for(int i=0;i<ccc;i++){
		swap(pc[i].x,pc[i].y);
	}
	sort(pd,pd+dd);
	sort(pc,pc+ccc);
	map<int,int> m;
	for(int i=dd-1,j=0;i>=0;i--){
		if(pd[i].x>d)
		continue;
		while(j<dd&&pd[j].x<=d-pd[i].x)m[pd[j].y]++,j++;
		if(i>=j&&m.size()!=0){
			map<int,int>::iterator it=m.end();it--;
			ans=max(ans,pd[i].y+it->x);
		}
		else if(m.size()!=0){
			m[pd[i].y]--;
			if(m[pd[i].y]==0)
			m.erase(pd[i].y);
			if(m.size()!=0){
				map<int,int>::iterator it=m.end();it--;
				ans=max(ans,pd[i].y+it->x);
			}
			m[pd[i].y]++;
		} 
	}
	//printf("%d\n",ans);
	m.clear();
	for(int i=ccc-1,j=0;i>=0;i--){
		while(j<ccc&&pc[j].x<=c-pc[i].x)m[pc[j].y]++,j++;
		if(i>j&&m.size()!=0){
			map<int,int>::iterator it=m.end();it--;
			ans=max(ans,pc[i].y+it->x);
		}
		else if(m.size()!=0){
			m[pc[i].y]--;
			if(m[pc[i].y]==0)
			m.erase(pc[i].y);
			if(m.size()!=0){
			map<int,int>::iterator it=m.end();it--;
			ans=max(ans,pc[i].y+it->x);
			}
			m[pc[i].y]++;
		} 
	}
	printf("%d\n",ans);
} 
//1 1 2 6 3 8 4 11 5 17 6 15 7 13 8 25 9 22 10 27
//1
//2 4 6 8 10
//3 6 9
//4 2 6 8 10
//5 5 10
//6 2 3 4 6 8 10