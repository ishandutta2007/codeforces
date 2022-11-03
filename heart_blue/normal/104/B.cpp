#include <iostream>
#include <vector>
using namespace std;
vector<long long> lvec;
int main()
{
    
    int n;
    cin >> n;
    long long temp = n;
    long long ans = n;
    for(int i = 0; i < n; i++)
    {
            cin >> temp;
            lvec.push_back(temp);
    }
    for(int i = lvec.size() - 1; i >= 0; i--)
    {
            ans += (lvec[i] - 1) * (i+1);
    }
    cout << ans << endl;
    return 0;
    
}