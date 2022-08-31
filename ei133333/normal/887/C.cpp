#include<bits/stdc++.h>

using namespace std;

bool check(string &s)
{
  return (s[1] == s[2] && s[2] == s[3] && s[3] == s[4] &&
          s[5] == s[6] && s[6] == s[7] && s[7] == s[8] &&
          s[9] == s[10] && s[10] == s[11] && s[11] == s[12] &&
          s[13] == s[14] && s[14] == s[15] && s[15] == s[16] &&
          s[17] == s[18] && s[18] == s[19] && s[19] == s[20] &&
          s[21] == s[22] && s[22] == s[23] && s[23] == s[24]);

}

bool check1(string &s)
{
  string t = s;
  t[5] = s[1];
  t[7] = s[3];
  t[9] = s[5];
  t[11] = s[7];
  t[22] = s[9];
  t[24] = s[11];
  t[3] = s[22];
  t[1] = s[24];
  return (check(t));

}

bool check2(string &s)
{
  string t = s;
  t[6] = s[2];
  t[8] = s[4];
  t[10] = s[6];
  t[12] = s[8];
  t[23] = s[10];
  t[21] = s[12];
  t[4] = s[21];
  t[2] = s[23];
  return (check(t));
}

bool check3(string &s)
{
  string t = s;
  t[13] = s[5];
  t[14] = s[6];
  t[5] = s[17];
  t[6] = s[18];
  t[17] = s[21];
  t[18] = s[22];
  t[21] = s[14];
  t[22] = s[13];
  return (check(t));
}

bool check4(string &s)
{
  string t = s;
  t[15] = s[7];
  t[16] = s[8];
  t[7] = s[19];
  t[8] = s[20];
  t[19] = s[23];
  t[20] = s[24];
  t[23] = s[16];
  t[24] = s[15];
  return (check(t));
}

bool check5(string &s)
{
  string t = s;
  t[5] = s[9];
  t[7] = s[11];
  t[9] = s[22];
  t[11] = s[24];
  t[22] = s[1];
  t[24] = s[3];
  t[3] = s[5];
  t[1] = s[7];
  return (check(t));
}

bool check6(string &s)
{
  string t = s;
  t[6] = s[10];
  t[8] = s[12];
  t[10] = s[21];
  t[12] = s[23];
  t[23] = s[2];
  t[21] = s[4];
  t[4] = s[6];
  t[2] = s[8];
  return (check(t));
}


bool check7(string &s)
{
  string t = s;
  t[13] = s[21];
  t[14] = s[22];
  t[5] = s[13];
  t[6] = s[14];
  t[17] = s[5];
  t[18] = s[6];
  t[21] = s[17];
  t[22] = s[18];
  return (check(t));
}


bool check8(string &s)
{
  string t = s;
  t[15] = s[23];
  t[16] = s[24];
  t[7] = s[15];
  t[8] = s[16];
  t[19] = s[7];
  t[20] = s[8];
  t[23] = s[19];
  t[24] = s[20];
  return (check(t));
}


bool check9(string &s)
{
  string t = s;
  t[14] = s[3];
  t[16] = s[4];
  t[3] = s[17];
  t[4] = s[19];
  t[17] = s[9];
  t[19] = s[10];
  t[9] = s[14];
  t[10] = s[16];
  return (check(t));
}


bool check10(string &s)
{
  string t = s;
  t[14] = s[9];
  t[16] = s[10];
  t[9] = s[17];
  t[10] = s[19];
  t[17] = s[3];
  t[19] = s[4];
  t[3] = s[14];
  t[4] = s[16];
  return (check(t));
}


bool check11(string &s)
{
  string t = s;
  t[13] = s[1];
  t[15] = s[2];
  t[1] = s[18];
  t[2] = s[20];
  t[18] = s[11];
  t[20] = s[12];
  t[11] = s[13];
  t[12] = s[15];
  return (check(t));
}


bool check12(string &s)
{
  string t = s;
  t[13] = s[11];
  t[15] = s[12];
  t[11] = s[18];
  t[12] = s[20];
  t[18] = s[1];
  t[20] = s[2];
  t[1] = s[13];
  t[2] = s[15];
  return (check(t));
}

int main()
{
  string A;
  A += "*";

  for(int i = 0; i < 24; i++) {
    string s;
    cin >> s;
    A += s;
  }

  if(check1(A) || check2(A) || check3(A) || check4(A) ||
     check5(A) || check6(A) || check7(A) || check8(A) ||
     check9(A) || check10(A) || check11(A) || check12(A)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}