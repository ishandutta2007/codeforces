#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>

using namespace std;

char s[5040][5];
int cnt = 0;

int rq[5041][8], rA[5041][8], rB[5041][8];

//User interface support

void getAB(int num, int &A, int &B)
{
    cout << s[num] << endl;
    cin >> A >> B;
    if (A == 4 && B == 0)
        exit(0);
}


//Main code

int dif(int a, int b, int &A, int &B)
{
    A = 0, B = 0;
    for (int i = 0; i < 4; i++)
        if (s[a][i] == s[b][i]) A++;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (s[a][i] == s[b][j]) B++;
    B -= A;
}

void genAll()
{
    for (char a = '0'; a <= '9'; a++)
        for (char b = '0'; b <= '9'; b++)
            if (a != b)
                for (char c = '0'; c <= '9'; c++)
                    if (a != c && b != c)
                        for (char d = '0'; d <= '9'; d++)
                            if (a != d && b != d && c != d)
                            {
                                s[cnt][0] = a;
                                s[cnt][1] = b;
                                s[cnt][2] = c;
                                s[cnt][3] = d;
                                cnt++;
                            }
}

int findIt(const char* a)
{
    for (int i = 0; i < cnt; i++)
        if (string(a) == string(s[i])) return i;
    return -1;
}

mt19937 rnd(165);

bool eqRequests(int a, int b, int sz)
{
    for (int i = 0; i < sz; i++)
        if (rA[a][i] != rA[b][i] || rB[a][i] != rB[b][i]) return false;
    return true;
}

bool guess()
{
    vector <int> v(cnt);
    for (int i = 0; i < cnt; i++) v[i] = i;
    int r[7];
    for (int i = 0; i < 8; i++)
    {
        vector <int> q = v; v.clear();
        r[i] = q[rnd() % q.size()];
        rq[cnt][i] = r[i];
        getAB(rq[cnt][i], rA[cnt][i], rB[cnt][i]);
        if (rA[cnt][i] == 4) return true;
        for (int j = 0; j < q.size(); j++)
            dif(rq[q[j]][i] = r[i], q[j], rA[q[j]][i], rB[q[j]][i]);
        for (int j = 0; j < q.size(); j++)
            if (eqRequests(cnt, q[j], i + 1)) v.push_back(q[j]);
        if (v.size() == 0) return false;
    }
    return false;
}

int main()
{
    genAll();
    guess();
}