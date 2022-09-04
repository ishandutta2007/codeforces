#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int val[105];
int v[105];
pair<int,int> p[105];
int hp[105],hp2[105];
int num[105];
int main(){
	int n,m;
	cin>>n>>m;
	memset(hp2,-1,sizeof(hp2));
	for(int i=0;i<m;i++){
		cin>>p[i].first>>p[i].second;
		hp2[p[i].first] = p[i].second;
	//	cout<<"hp "<<p[i].first<<" = "<<p[i].second<<endl;
		num[p[i].first] = i+1;
	}
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	
	for(int i=1;i<=n;i++){
	//	cout<<"i = "<<i<<endl;
		for(int j=1;j<=n;j++){
			v[j] = val[j];
			hp[j] = hp2[j];
		}
	//	cout<<"hp : ";
	//	for(int j=1;j<=n;j++){
	//		cout<< hp[j] << ' ';
	//	}
	//	cout<<endl;
		vector<int> ansV;
		ansV.clear();
		while(ansV.size()<m){
			int flag = 0;
			for(int j=0;j<=n;j++){
		//		cout<<"j = "<<j<<' '<<i-j<<' '<<hp[i-j]<<endl;
				if(i-j>=1 && hp[i-j]!=-1){
				//	cout<<"hi "<<i-j<<endl;
					int now = hp[i-j];
					int key = 0;
					for(int k=i-j;k<=i;k++){
			//			cout<<"k = "<<k<<' '<<v[k]<<endl;
						now+=v[k];
				//		cout<<"now = "<<now<<endl;
						if(now<0) key = 1;
					}
					if(key==0){
					//	cout<<"hi2 "<<i-j<<endl;
						hp[i-j]=-1;
						flag=1;
						ansV.pb(num[i-j]);
						for(int k=i-j;k<=i;k++){
					//		cout<<"bye "<<k<<endl;
							v[k] = 0;
							if(hp[k] != -1){
						//		cout<<"hi3 "<<k<<' '<<hp[k]<<endl;
								ansV.pb(num[k]);
								hp[k] = -1;
							}
							
						}
					}
				}
				if(i+j<=n && hp[i+j]!=-1){
			//		cout<<"hi "<<i+j<<endl;
					int now = hp[i+j];
					int key = 0;
					for(int k=i+j;k>=i;k--){
					//	cout<<"k = "<<k<<' '<<v[k]<<endl;
						now+=v[k];
					//	cout<<"now = "<<now<<endl;
						if(now<0) key = 1;
					}
					if(key==0){
					//	cout<<"hi2 "<<i+j<<endl;
						hp[i+j]=-1;
						flag=1;
						ansV.pb(num[i+j]);
						for(int k=i+j;k>=i;k--){
						//	cout<<"bye "<<k<<' '<<hp[k]<<endl;
							v[k] = 0;
							if(hp[k] != -1){
							//	cout<<"hi3 "<<k<<endl;
								ansV.pb(num[k]);
								
								hp[k] = -1;
							}
						}
					}
				}
			}
		//	cout<<"flag = "<<flag<<' '<<ansV.size()<<endl;
			if(flag==0){
				break;
			}
		}
	//	cout<<"cnt m = "<<ansV.size()<<' '<<m<<endl;
		if(ansV.size() == m){
			cout<<i<<endl;
			for(int j=0;j<ansV.size();j++){
				if(j>0) cout<<' ';
				cout<<ansV[j];
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	
	return 0;
}