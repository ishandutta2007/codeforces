/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	dfs or bfs
	//
	c[i]
	
	long long
	
	dp
	
	:AABAB
	 >=0
	
	double> printf("%lf")6%.16lf
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<ceil(log2(double(n)))
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<int/*color*/,int/*location*/> MP;
int n,p[300001],m,flag[300002],sum[300005];
struct node{
	int u;
	int v;
}path[500001];
inline int super_read(){
	char tmpc;
	int num=0;
	while(1){
		tmpc=getchar();
		if(tmpc>='0'&&tmpc<='9'){
			num=(num<<3)+(num<<1);
			num+=tmpc^48;
		}
		else return num;
	}
	return false;
}
bool cmp(node A,node B){if(A.u!=B.u) return A.u>B.u;return A.v<B.v;}
int main(){
//		freopen("out.out","r",stdin);
	n=super_read();m=super_read();
	rb(i,1,n) p[i]=super_read(),MP[p[i]]=i;
	rb(i,1,m){
		int ui,vi;
		ui=super_read();
		vi=super_read();
		if(MP[ui]==n) continue;
		path[i].u=MP[ui];
		path[i].v=MP[vi];
	}
	sort(path+1,path+1+m,cmp);
	int lastPERSON=n+1,last=-1,OK=0,rec=0;
	rb(i,1,m){
		if(path[i].u!=lastPERSON){
//			cout<<"OK"<<" "<<path[i].u<<endl;
			if(last==n&&OK){
//				cout<<path[i-1].u<<endl;
//				cout<<i<<endl;
				rec++;
				flag[lastPERSON]=1;
			}
			sum[lastPERSON]=sum[lastPERSON+1]+flag[lastPERSON];
			for(int j=path[i].u-1;j>lastPERSON;j--){
				sum[j]=sum[lastPERSON];
			}
			lastPERSON=path[i].u;
			last=lastPERSON;
			OK=1;
		}
		if(path[i].v<=last||!OK) continue;
		else{
			if(path[i].v==last+1||sum[last+1]-sum[path[i].v]==path[i].v-last-1){
				last=path[i].v;
			}
			else{
				OK=0;
			}
		}
	}	
	if(last==n&&OK){
		rec++;
		flag[lastPERSON]=1;
	}
//	if(flag[n]) rec--;
//	rb(i,1,n){
//		cout<<flag[i]<<" ";
//	}cout<<endl;
	printf("%d\n",rec);
	return 0;
}