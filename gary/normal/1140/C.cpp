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
#define ULL long long
#define rb(a,b,c) for(ULL a=b;a<=c;a++)
#define rl(a,b,c) for(ULL a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second

using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
	ULL t,b;
}a[300001];
bool cmp(node A,node B){
	return A.b<B.b;
}
bool cmp1(ULL A,ULL B){
	return A>B;
}
int main(){
//	freopen("in.in","r",stdin);
	ULL n,k,ans=0;
	scanf("%I64d %I64d",&n,&k);
	rb(i,1,n){
		scanf("%I64d %I64d",&a[i].t,&a[i].b);
	}
		if(k==1){
		ULL finalans=0;
		rb(i,1,n){
			finalans=max(finalans,a[i].t*a[i].b);
		}
		cout<<finalans<<endl;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
//	priority_queue<ULL,vector<ULL>, less<ULL> > q;
	multiset<ULL> v;
//	ULL vhave=0;
	ULL sum=0;
	rl(i,n,1){
		ULL tmpans=a[i].b*a[i].t+sum*a[i].b	;
//		sum++;
//		cout<<sum<<endl;
		ans=max(tmpans,ans);
		if(v.size()!=k-1){
			v.insert(a[i].t);
			sum+=a[i].t;
		}
		else{
//			cout<<v.size()<<endl;
			multiset<ULL>::iterator ite=v.begin();
//			ite--;
//			cout<<*ite<<" "<<a[i].t<<endl;
			if(*ite<a[i].t){
//				cout<<*ite<<endl;
				sum-=*ite;
				sum+=a[i].t;
				v.erase(ite);
				v.insert(a[i].t);
//				sort(v.begin(),v.end(),cmp1);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}