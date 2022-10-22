/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	c[i]
	
	long long
	
	dp
	
	 >=0
	
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
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
//typedef pair<int,int> mp;
//typedef pair<mp,mp> superpair;
//map<int,int> mp[500][500];
int main(){
//	freopen("out.out","r",stdin);
	int a1[505][505],a2[505][505];
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		rb(j,1,m){
			scanf("%d",&a1[i][j]);
			
		}
	}
	rb(i,1,n){
		rb(j,1,m){
			scanf("%d",&a2[i][j]);
		}
	}
	rb(i,1,m){
		map<int,int> mp1;map<int,int> mp2;
		int x=1,y=i;
//		bool OK=0;
		while(x<=n&&y>=1){
			mp1[a1[x][y]]++;
			mp2[a2[x][y]]++;
			x++;
			y--;
		}
		if(mp1!=mp2){
			cout<<"NO";
			return 0;
		}
//		if(!OK){
	}
	rb(i,2,n){
		map<int,int> mp1;map<int,int> mp2;
		int x=i,y=m;
//		bool OK=0;
		while(x<=n&&y>=1){
			mp1[a1[x][y]]++;
			mp2[a2[x][y]]++;
			x++;
			y--;
		}
		if(mp1!=mp2){
			cout<<"NO";
			return 0;
		}
//		if(!OK){
	}
	cout<<"YES";
	return 0;
}