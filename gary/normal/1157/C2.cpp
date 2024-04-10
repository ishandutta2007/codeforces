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
int flag;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,a[200001];
int last=-MAX;
vector<char> v;
int check(int l,int r){
//	cout<<l<<" "<<r<<endl;
	if(l>r){
		flag=1;
		return 0;
	}
	if(a[l]==a[r]){
		return check(l+1,r-1)+1;
	}
	else{
		if(a[l]<a[r]) flag=1;
		else flag=2;
		return 0;
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	int l=1,r=n;
	while(l<=r){
		if(max(a[l],a[r])<=last){
			printf("%d\n",v.size());
			rb(i,0,v.size()-1) {
				printf("%c",v[i]);
			}
			return 0;
		}
		if(a[l]==a[r]){
			int to=check(l,r);
//			cout<<to<<endl;
			int now=l+to-1,lreach=0,rreach=0;
			int tmplast=-0x3f3f3f3f;
			while(now<=r){
//				cout<<a[now]<<tmplast<<endl;
				if(a[now]<=tmplast) break;tmplast=a[now];
				now++;lreach++;
			}
			now=r-to+1;
			tmplast=-0x3f3f3f3f;
			while(now>=l){
//				cout<<tmplast<<a[now]
				if(a[now]<=tmplast) break;tmplast=a[now];
				now--;rreach++;
			}
			lreach--;
			rreach--;
//			cout<<lreach<<" "<<rreach<<endl; 
			if(lreach>rreach){
				flag=1;
			}
			else{
				flag=2;
			}
			if(flag==1){
			for(int i=1;i<=to;i++){
				if(a[l]<=last){
					printf("%d\n",v.size());
			rb(i,0,v.size()-1) {
				printf("%c",v[i]);
			}
			return 0;
				}
				last=a[l];
				l++;
				v.push_back('L');
			}
			for(int i=1;i<=lreach;i++){
				if(a[l]<=last){
					printf("%d\n",v.size());
			rb(i,0,v.size()-1) {
				printf("%c",v[i]);
			}
			return 0;
				}
				last=a[l];
				l++;
				v.push_back('L');
			}	
			}
			else{
				for(int i=1;i<=to;i++){
					if(a[r]<=last){
						printf("%d\n",v.size());
			rb(i,0,v.size()-1) {
				printf("%c",v[i]);
			}
			return 0;	
					}
				last=a[r];
				r--;
				v.push_back('R');
			}
			for(int i=1;i<=rreach;i++){
				if(a[r]<=last){
						printf("%d\n",v.size());
			rb(i,0,v.size()-1) {
				printf("%c",v[i]);
			}
			return 0;	
					}
					last=a[r];
				r--;
				v.push_back('R');
			}
			}
			continue;
		}
		if((a[l]<a[r]&&a[l]>last)||a[r]<=last){
			flag=1;
		}
		else{
			flag=2;
		}
		if(flag==1){
//			cout<<"Choose L"<<a[l]<<" "<<a[r]<<endl; 
			v.push_back('L');
			last=a[l++];
		}
		else{
//			cout<<"Choose R"<<a[l]<<" "<<a[r]<<endl; 
			v.push_back('R');
			last=a[r--];
		}
	}
	printf("%d\n",v.size());
			rb(i,0,v.size()-1) {
				printf("%c",v[i]);
			}
	return 0;
}