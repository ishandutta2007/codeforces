#include <iostream>
#include <deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        deque<int> D;
        for(int i=0; i<N; ++i)
        {
            int t; cin >> t;
            if(D.empty() || t < D.front()) D.push_front(t);
            else D.push_back(t);
        }
        for(int x: D) cout << x << ' ';
        cout << endl;
    }
}