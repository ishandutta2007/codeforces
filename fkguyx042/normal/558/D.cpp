#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int H, Q, Res;
long long L, R, X, Y;
vector<pair<long long, long long> > Union, Segs;
inline bool Cross(pair<long long, long long> &A, const pair<long long, long long> &B)
{
    if (A.first < B.first)
    {
        if (A.second > B.second)
        {
            puts("Data not sufficient!");
            exit(0);
        }else
        {
            A.second = min(A.second, B.first - 1);
            return true;
        }
    }
    A.first = max(A.first, B.second + 1);
    if (A.second < A.first)
    {
        puts("Game cheated!");
        exit(0);
    }
    return false;
}
int main()
{
    scanf("%d%d", &H, &Q);
    L = 1LL << (H - 1), R = (1LL << H) - 1;
    while (Q --)
    {
        int i;
        scanf("%d", &i);
        scanf("%I64d%I64d%d", &X, &Y, &Res);
        X <<= H - i, Y <<= H - i;
        Y += (1LL << (H - i)) - 1;
        if (Res) L = max(X, L), R = min(R, Y);
        else Union.push_back(make_pair(X, Y));
    }
    sort(Union.begin(), Union.end());
    if (L > R)
    {
        puts("Game cheated!");
        return 0;
    }
    Segs.push_back(make_pair(-10LL, -10LL));
    for (int i = 0; i < Union.size(); i ++)
    {
        int X = Segs.size() - 1;
        if (Segs[X].second + 1 >= Union[i].first) Segs[X].second = max(Segs[X].second, Union[i].second);
        else Segs.push_back(Union[i]);
    }
    pair<long long, long long> CurRes = make_pair(L, R);
    for (int  i = 1;i < Segs.size(); i ++)
        if (Cross(CurRes, Segs[i])) break;
    
    if (CurRes.first == CurRes.second) printf("%I64d\n", CurRes.first);
    else puts("Data not sufficient!");
    return 0;
}