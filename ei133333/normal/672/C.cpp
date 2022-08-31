#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

struct Point
{
  int64 x, y;
};


Point a, b, t, p[100000];
double to[100000];
int64 N;

double dist(Point xx, Point yy)
{
  return(sqrt((xx.x - yy.x) * (xx.x - yy.x) + (xx.y - yy.y) * (xx.y - yy.y)));
}

int main()
{  
  
  cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
  cin >> N;
  double sum = 0;
  vector< pair< double, int > > Anear, Bnear;
  for(int i = 0; i < N; i++) {
    cin >> p[i].x >> p[i].y;
    sum += dist(t, p[i]) * 2.0;
    Anear.push_back({dist(a, p[i]) - dist(t, p[i]), i});
    Bnear.push_back({dist(b, p[i]) - dist(t, p[i]), i});
  }
  
  sort(Anear.begin(), Anear.end());
  sort(Bnear.begin(), Bnear.end());

  double best = min(Anear[0].first, Bnear[0].first);
  if(N > 1) {
    if(Anear[0].second == Bnear[0].second) {
      best = min({best, Anear[0].first + Bnear[1].first, Anear[1].first + Bnear[0].first});
    } else {
      best = min(best, Anear[0].first + Bnear[0].first);
    }
  }
  cout << fixed << setprecision(15) << sum + best << endl;
}