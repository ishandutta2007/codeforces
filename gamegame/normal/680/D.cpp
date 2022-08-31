#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long m;
	cin >> m;
	long long int cost[125],cost2[125],cost3[125],a[100001],b[100001];
	int n=cbrt(m);
	if(n*n*n!=m){
		n++;
	}
	cost[0]=cost2[0]=0;
	for(int i=1; i<125 ;i++){
		int j=i;
		while(j>=64){ cost[i]++; j-=64; }
		while(j>=27){ cost[i]++; j-=27; }
		while(j>=8){ cost[i]++; j-=8; }
		while(j>=1){ cost[i]++; j-=1; }
		a[5]=max(a[5],cost[i]);
		if(cost[i]>=cost2[i-1]){
			cost3[i]=i;
		}
		else{
			cost3[i]=cost3[i-1];
		}
		cost2[i]=max(cost[i],cost2[i-1]);
	}
	if(m<125){
		cout << cost2[m] << ' ' << cost3[m] << endl;
		return 0;
	}
	a[5]=cost2[124],b[5]=cost3[124];
	for(long long int i=6; i<=100000 ;i++){
		a[i]=a[i-1];
		b[i]=b[i-1];
		long long int taken=0,left=i*i*i-1;
		long long c=0;
		long long int l=5,r=i,mid;
		while(true){
			r--;
			l=5;
			if(r<l || l*l*l>left){
				break;
			}
			while(l!=r){
				mid=(l+r+1)/2;
				if(mid*mid*mid<=left){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
			left-=l*l*l;
			if(taken+a[l]>a[i] || taken+a[l]==a[i] && b[l]+c>b[i]){
				a[i]=taken+a[l];
				b[i]=b[l]+c;
			}
			c+=l*l*l;
			taken++;
		}
		if(taken+cost2[left]>a[i] || taken+cost2[left]==a[i] && cost3[left]+c>b[i]){
			a[i]=taken+cost2[left];
			b[i]=cost3[left]+c;
		}
	}
	long long aa=0,bb=0,taken=0,c=0;
	for(long long i=100000; i>=5 ;i--){
		if(i*i*i<=m){
			m-=i*i*i;
			if(a[i]+taken>aa || a[i]+taken==aa && b[i]+c>bb){
				aa=a[i]+taken;
				bb=b[i]+c;
			}
			c+=i*i*i;
			taken++;
		}
	}
	if(taken+cost2[m]>aa || taken+cost2[m]==aa && cost3[m]+c>bb){
		aa=taken+cost2[m];
		bb=cost3[m]+c;
	}
	cout << aa << ' ' << bb << endl;
}