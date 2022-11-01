#include <bits/stdc++.h>
using namespace std;

string s;
int rj = 0;

int main()
{
    cin >> s;
    int otvorene, upitnici, nepokrivene;
    for (int i = 0; i < s.size(); i++)
    {
        otvorene = 0;
        upitnici = 0;
        nepokrivene = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (s [j] == '(')
            {
                otvorene++;
                nepokrivene++;
            }
            else if (s [j] == ')')
            {
                otvorene--;
                nepokrivene--;
            }
            else
            {
                upitnici++;
                nepokrivene--;
            }
            if (nepokrivene < 0) nepokrivene = 0;
            if (otvorene < 0 && upitnici)
            {
                otvorene = 0;
                upitnici--;
            }
            else if (otvorene < 0) break;
            if (!nepokrivene && (otvorene + upitnici) % 2 == 0) rj++;
        }
    }
    cout << rj;
    return 0;
}