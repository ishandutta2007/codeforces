#include <bits/stdc++.h>

using namespace std;

const string tt = ".,!? ";

bool solve()
{
  int N, M;
  cin >> N;
  vector< string > S(N);
  for(int i = 0; i < N; i++) cin >> S[i];
  cin >> M;
  cin.ignore();

  vector< pair< int, vector< int > > > vc;
  vector< string > kk(M);

  for(int i = 0; i < M; i++) {
    string K;
    getline(cin, K);
    kk[i] = K;

    int idx = 0;
    string name;
    vector< int > word;
    while(idx < K.size() && K[idx] != ':') name += K[idx++];
    ++idx;

    string pico;
    while(idx < K.size()) {
      if(tt.find(K[idx]) != string::npos) {
        idx++;
        if(pico.size()) {
          if(find(begin(S), end(S), pico) != end(S)) {
            word.push_back((int) (find(begin(S), end(S), pico) - begin(S)));
          }
          pico = "";
        }
        continue;
      }
      pico += K[idx++];
    }
    if(pico.size()) {
      if(find(begin(S), end(S), pico) != end(S)) {
        word.push_back((int) (find(begin(S), end(S), pico) - begin(S)));
      }
    }
    if(find(begin(S), end(S), name) == end(S)) {
      if(name != "?") return (false);
    }
    vc.emplace_back((int) (find(begin(S), end(S), name) - begin(S)), word);
  }

  vector< vector< int > > koho;

  for(int i = 0; i < M; i++) {
    int namepos = vc[i].first;
    vector< int > cann;
    if(namepos == N) { // question
      for(int j = 0; j < N; j++) {
        int proc = 0;
        for(int k : vc[i].second) proc += j == k;
        if(proc == 0) cann.push_back(j);
      }
    } else {
      for(int k : vc[i].second) if(namepos == k) return(false);
      cann.push_back(vc[i].first);
    }
    if(cann.empty()) return (false);
    koho.push_back(cann);
  }


  vector< vector< int > > dp(M, vector< int >(N, 0));
  vector< vector< int > > pv(M, vector< int >(N, -1));
  for(auto &k : koho[0]) dp[0][k] = true;
  for(int i = 1; i < M; i++) {
    for(int j : koho[i]) {
      for(int k = 0; k < N; k++) {
        if(j == k) continue;
        if(!dp[i - 1][k]) continue;
        dp[i][j] = true;
        pv[i][j] = k;
        break;
      }
    }
  }

  int cnt = -1;
  for(int j = 0; j < N; j++) if(dp[M - 1][j]) cnt = j;

  if(cnt == -1) return(false);

  vector< string > people;


  people.push_back(S[cnt]);
  for(int j = M - 2; j >= 0; j--) {
    cnt = pv[j + 1][cnt];
    people.push_back(S[cnt]);

  }

  reverse(begin(people), end(people));


  for(int i = 0; i < M; i++) {
    cout << people[i] << ":";
    string K = kk[i];
    int idx = 0;
    vector< int > word;
    while(idx < K.size() && K[idx] != ':') ++idx;
    ++idx;
    cout << K.substr(idx) << endl;
  }
  return (true);
}


int main()
{
  int T;
  cin >> T;
  while(T--) {
    if(!solve()) cout << "Impossible" << endl;
  }
}