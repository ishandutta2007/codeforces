#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

map<string, bool> exist;
map<string, int> score;
vector<int> iv;

int main(void)
{
    int noob = -1, ran = -1, average = -1, hardcore = -1;
    int n, i, j, k;
    cin >> n;
    string s;
    for (i = 0; i < n; ++i)
    {
        cin >> s >> k;
        if (exist[s])
        {
            if (score[s] < k)
                score[s] = k;
        }
        else
        {
            exist[s] = true;
            score[s] = k;
        }
    }
    k = 0;
    for (map<string, bool>::iterator it = exist.begin(); it != exist.end(); ++it)
    {
        iv.push_back(score[it->first]);
        ++k;
    }
    sort(iv.begin(), iv.end());
    j = k;
    for (i = k - 1; i >= 1; --i)
    {
        if (iv[i - 1] != iv[j - 1])
        {
            j = i;
            if ((j * 100 < k * 99) && (hardcore == -1))
                hardcore = iv[j - 1];
            if ((j * 100 < k * 90) && (average == -1))
                average = iv[j - 1];
            if ((j * 100 < k * 80) && (ran == -1))
                ran = iv[j - 1];
            if ((j * 100 < k * 50) && (noob == -1))
                noob = iv[j - 1];
        }
    }
    cout << k << "\n";
    for (map<string, bool>::iterator it = exist.begin(); it != exist.end(); ++it)
    {
        string nam = it->first;
        int sc = score[it->first];
        if ((noob != -1) && (sc <= noob))
        {
            cout << nam << " noob\n";
            continue;
        }
        if ((ran != -1) && (sc <= ran))
        {
            cout << nam << " random\n";
            continue;
        }
        if ((average != -1) && (sc <= average))
        {
            cout << nam << " average\n";
            continue;
        }
        if ((hardcore != -1) && (sc <= hardcore))
        {
            cout << nam << " hardcore\n";
            continue;
        }
        cout << nam << " pro\n";
    }
    return 0;
}