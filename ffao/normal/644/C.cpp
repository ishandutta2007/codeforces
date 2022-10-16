#include <bits/stdc++.h> 

using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
char s[1100];
int totpt, tothn;
map<string, int> paths;
map<string, int> hostnames;
string hn_vals[110000];
pair< vector<int>, int > querysets[110000];

void solve() {
	scanf("%d", &n);

	REP(i,n) {
		scanf("%s", s);
		int j, c=0;
		for (j = 0; s[j] != '\0'; j++) {
			if (s[j]=='/') c++;
			if (c == 3) break;
		}
		string k = s;
		string hns = k.substr(0,j);
		string pts = k.substr(j);
		if (!paths.count(pts)) paths[pts] = totpt++;
		if (!hostnames.count(hns)) {
			hn_vals[tothn] = hns;
			querysets[tothn].second = tothn;
			hostnames[hns] = tothn++;
		}

		int hn = hostnames[hns], pt = paths[pts];
		querysets[hn].first.push_back(pt);
	}

	REP(i,tothn) {
		sort(querysets[i].first.begin(), querysets[i].first.end());
		querysets[i].first.resize(unique(querysets[i].first.begin(), querysets[i].first.end()) - querysets[i].first.begin());
	}
	sort(querysets, querysets+tothn);

	vector< vector<int> > gr;

	int la = 0;
	REP(i, tothn) {
		if (i == tothn-1 || querysets[i].first != querysets[i+1].first) {
			if (i > la) {
				vector<int> tg;
				for (int j = i; j >= la; j--) {
					tg.push_back(querysets[j].second);
				}
				gr.push_back(tg);
			}
			la = i+1;
		}
	}

	printf("%d\n", gr.size());
	REP(i, gr.size()) {
		REP(j, gr[i].size()) {
			printf("%s ", hn_vals[gr[i][j]].c_str());
		}
		printf("\n");
	}
}

int main() {
    solve();
}