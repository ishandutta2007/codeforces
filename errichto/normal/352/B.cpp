#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int> > a;
	vector<pair<int,int> > all;
	for(int i=0; i<n; i++) {
		int temp;
		cin>>temp;
		a.push_back(make_pair(temp,i));
	}

	sort(a.begin(), a.end());
	int lastVal = a[0].first;
	int diff = 0;
	int lastPos = a[0].second;
	int count = 0;
	if(a.size()==1){
		cout<<1<<endl;
		cout<<lastVal<<" "<<0<<endl;
		return 0;
	}
	for(int i=1; i<n; i++){
		//printf("%d %d\n", i, (int) all.size());
		if(a[i].first == lastVal){
			if(diff==0){
				diff = a[i].second - lastPos;
				lastPos = a[i].second;
				count++;
			}
			else{
				if(diff== a[i].second - lastPos){
					lastPos = a[i].second;
					count++;
				}
				else{
					count = -1;
					while(a[i].first == lastVal) {
						//puts("plis");
						i++;
						if(i==n) break;
					}
					i--;
				}
			}
		}
		else{
			//cout<<lastVal<<endl;
			if(count >= 0) all.push_back(make_pair(lastVal, diff));
			lastVal = a[i].first;
			count = 0;
			diff = 0;
			lastPos = a[i].second;
		}
	}
	if(count>=0){
		all.push_back(make_pair(lastVal, diff));
	}

	cout<<all.size()<<endl;
	for(int i=0; i<all.size(); i++){
		cout<<all[i].first<<" "<<all[i].second<<endl;
	}
}