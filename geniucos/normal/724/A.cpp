#include<bits/stdc++.h>

using namespace std;

int N, ap[10], X, Y;
int l[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string v[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

char aa[100], bb[100];
string a, b;
gets (aa), gets (bb), a = aa, b = bb;
for (int i=0; i<7; i++)
    if (a == v[i]) X = i;
for (int i=0; i<7; i++)
    if (b == v[i]) Y = i;
for (int j=0; j<12; j++)
    ap[l[j] % 7] = 1;
if (ap[(Y - X + 7) % 7]) printf ("YES\n");
else printf ("NO\n");
return 0;
}