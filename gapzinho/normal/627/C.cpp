#include<bits/stdc++.h>
using namespace std;
const int ms = 2e5 + 10;
const long long inf = 1e15;

int nxt[ms];
int d,n,m;

vector<pair<int,int>>val;
void process(){
	//iii = {custo, posicao, id}
	using iii = tuple<int,int,int>;
	priority_queue<iii,vector<iii>,greater<iii>>pq;
    stack<iii> st;
	for(int i=m+1;i>=0;--i){
		while(!pq.empty() && get<1>(pq.top()) - val[i].first > n){
			pq.pop();
		}
        while(!st.empty() && (get<1>(st.top()) - val[i].first > n || get<0>(st.top()) >= val[i].second)) {
            st.pop();
        }
        if(!st.empty()) nxt[i] = get<2>(st.top());
		else nxt[i] = pq.empty() ? i : get<2>(pq.top());
		pq.push({val[i].second,val[i].first,i});
        st.push({val[i].second,val[i].first,i});
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>d>>n>>m;
	val.assign(m + 2,{});
	for(int i=1;i<=m;++i){
		int x,p;
		cin>>x>>p;
		val[i] = {x,p};
	}
	val[0] = {0, 1e9+7};
	val[m + 1] = {d, 0};
	sort(begin(val),end(val));
	process();
	bool ok = true;
	int gas = n;
	long long ans = 0;
	for(int i = 0; i != m + 1; i = nxt[i]){
		if(val[i].first + gas >= d)break;
		//cout<<i<<' '<<gas<<' '<<ans<<'\n';
		if(i == nxt[i]){
			ok = false;
			break;
		}
		int need = val[nxt[i]].first - val[i].first;
		if(val[nxt[i]].second > val[i].second){
			int gasFinal = d - val[i].first;
			// if(gasFinal <= n && gas <= gasFinal){
			// 	ans += 1ll*(gasFinal - gas)*val[i].second;
			// 	break;
			// }
			ans += 1ll*(n- gas)*val[i].second;
			gas = n;
		}else if(gas < need){
			ans += 1ll*(need - gas)*val[i].second;
			gas = need;
		}
		gas -= need;
		//cout<<i<<' '<<gas<<' '<<ans<<'\n';
		//cout<<'\n';
	}
	if(!ok)ans = -1;
	cout<<ans<<'\n';
    return 0;
}