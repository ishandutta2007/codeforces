#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long> > v[2];

int main(){
	long long t, a, b;
	cin >> t >> a >> b;
	if(t == a){
		if(a != b){
			cout << "0" << endl;
		}
		else if(t == 1){
			cout << "inf" << endl;
		}
		else{
			cout << "2" << endl;
		}
		return 0;
	}
	if(a < t){
		if(a == b){
			cout << "1" << endl;
		}
		else{
			cout << "0" << endl;
		}
		return 0;
	}
	if((a-b)%(t-a)){
		cout << "0" << endl;
		return 0;
	}
	bool read=0, write=1;
	long long tp=t, ap=a;
	v[write].push_back(make_pair(a, b));
	for(int i=32; i >= 2; --i){
		/*if(a/t < tp)
			break;
		if(b/a < ap)
			break;*/
		tp=1;
		ap=1;
		for(int j=0; j < i; ++j){
			if(a/t < tp)
				tp=a+1;
			else
				tp=tp*t;
			if(b/a < ap)
				ap=b+1;
			else
				ap=ap*a;
		}
		write^=1;
		read^=1;
		v[write].clear();
		for(int j=0; j < v[read].size(); ++j){
			long long A=v[read][j].first;
			long long B=v[read][j].second;
			for(int k=0; tp*k <= A && ap*k <= B; ++k){
				long long nA=A-tp*k;
				long long nB=B-ap*k;
				if(tp <= a && ap <= b && tp >= t && ap >= a && nA/(tp/t) < nB/(ap/a))
					continue;
				v[write].push_back(make_pair(A-tp*k, B-ap*k));
			}
		}
	}
	long long ans=0;
	for(int i=0; i < v[write].size(); ++i){
		long long A=v[write][i].first;
		long long B=v[write][i].second;
		if((A-B)%(t-a))
			continue;
		long long c1=(A-B)/(t-a);
		long long c0=A-c1*t;
		if(c1 >= 0 && c0 >= 0)++ans;
	}
	cout << ans << endl;
}