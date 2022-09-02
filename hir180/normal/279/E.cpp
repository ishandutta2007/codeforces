#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	string str;
	cin >> str;
	int ans=0;
	int s=str.size();
	vector<pair<int,int> > vec;
	int last=0,len=0,dis=0,han=0;
        bool ren=false;
	for(int i=0;i<s;i++){
		 if(ren) len++;
		if(str[i]=='1'){
			dis=0;
			han++;
			if(!ren) last=i; ren=true;
		}else{
			if(dis==1 && han){ ren=false;
			if(han>=2){
				vec.push_back(make_pair(last,len-1));
			}else{
				ans++;
			}
				len=0; han=0; dis=0;
			}else{
				dis++;
			}
		}
	}
	if(han){
		vec.push_back(make_pair(last,len-dis+1));
	}
	for(int i=0;i<vec.size();i++){
		int be=vec[i].first,sd=0;
		for(int j=be;j<be+vec[i].second;j++){
			if(str[j]=='0'){
				sd++;
			}
		}
		ans+=vec[i].second-sd==1?1:min(vec[i].second-sd,(sd+2));
	}
	cout << ans << endl;
	return 0;
}