#include<bits/stdc++.h>

using namespace std;

int N;
string a, b;

string Read ()
{
    char sir[100];
    scanf ("%s", sir);
    string s = sir;
    return s;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

a = Read (), b = Read ();
scanf ("%d\n", &N);
printf ("%s %s\n", a.c_str (), b.c_str ());
while (N --)
{
    string c = Read (), d = Read ();
    if (c == a) a = d;
    else b = d;
    printf ("%s %s\n", a.c_str (), b.c_str ());
}

return 0;
}