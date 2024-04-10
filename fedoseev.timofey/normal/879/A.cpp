# include <iostream>
# include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector <pair <long long, long long>> doc(n);
    for (int i = 0; i < n; ++i) cin >> doc[i].first >> doc[i].second;
    long long cur_day = doc[0].first;
    for (int i = 1; i < n; ++i) {
        long long j = doc[i].first;
        while (j <= cur_day) {
            j += doc[i].second;
        }
        cur_day = j;
    }
    cout << cur_day << endl;
}