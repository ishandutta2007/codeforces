#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const int maxlg = 30;
map<int, int> arr[maxlg];
ll sum[maxlg];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, x;
    char ch;
    int cnt = 0;
    cin>>q;
    while(q--){
    	cin>>ch>>x;
    	for(int i = maxlg-1; i >= 0; i--){
    		if(x&(1<<i)){
    			if(ch == '+'){
    				arr[i][x]++;
    				sum[i] += x;
    				cnt++;
    			}else{
    				arr[i][x]--;
    				sum[i] -= x;
    				cnt--;
    				if(arr[i][x] == 0){
    					arr[i].erase(x);
    				}
    			}
    			break;
    		}
    	}
    	ll tmp = 0;
    	int ans = cnt;
    	for(int i = 0; i < maxlg; i++){
    		if(!arr[i].empty() && tmp*2 < (*arr[i].begin()).first)ans--;
    		tmp += sum[i];
    	}
    	cout<<ans<<endl;
    }

}