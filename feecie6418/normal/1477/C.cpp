#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x[5005],y[5005],pl[5005],isin[5005];
ll Cross(int i,int j,int k){
	return 1ll*(x[j]-x[i])*(x[k]-x[j])+1ll*(y[j]-y[i])*(y[k]-y[j]);
}
int main(){
	//srand(time(0));
	//while(1){
		cin>>n;
//		set<pair<int,int> > s;
//	for(int i=1;i<=n;i++){
//		x[i]=rand()%10,y[i]=rand()%10;
//		while(s.count(make_pair(x[i],y[i])))x[i]=rand()%10,y[i]=rand()%10;
//		s.insert(make_pair(x[i],y[i]));
//	}
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	pl[1]=1,pl[2]=2;
	for(int i=3;i<=n;i++){
		if(Cross(pl[i-2],pl[i-1],i)<0)pl[i]=i;
		else {
			for(int j=2;j<i;j++){
				if(Cross(pl[j-1],i,pl[j])<0){
					if(j>2&&Cross(pl[j-2],pl[j-1],i)>=0)continue;
					if(j<i-1&&Cross(i,pl[j],pl[j+1])>=0)continue;
					for(int k=i;k>j;k--)pl[k]=pl[k-1];
					pl[j]=i;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<pl[i]<<' ',assert(pl[i]);
	cout<<endl;
	for(int i=2;i<n;i++)assert(Cross(pl[i-1],pl[i],pl[i+1])<0);
	//}
	
}