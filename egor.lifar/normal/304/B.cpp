

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool visokosn(int x) {
  if((x % 4 != 0) || (x % 100 == 0 && x % 400 != 0)){
    return false;
  }
  return true;
}


int main() {
  int y1, m1, d1, y2, m2, d2;
  scanf("%d:%d:%d", &y1, &m1, &d1);
  scanf("%d:%d:%d", &y2, &m2, &d2);
  if(y1 == y2 && m1 == m2 && d1 == d2) {
    printf("0\n");
    return 0;
  }
  if(y1 > y2) {
    int v = y1;
    y1 = y2;
    y2 = v;
    v = m1;
    m1 = m2;
    m2 = v;
    v = d1;
    d1 = d2;
    d2 = v;
  }
 
   if(y1 == y2 && m1 > m2) {
    int v = m1;
    m1 = m2;
    m2 = v;
    v = d1;
    d1 = d2;
    d2 = v;
  }
   if(y1 == y2 && m1 ==  m2 && d1>d2) {
    int v = d1;
    d1 = d2;
    d2 = v;
  }
  int a[12];
  a[0] = 0;
  a[1] = 31;
  a[2] = 28;
  a[3] = 31;
  a[4] = 30;
  a[5] = 31;
  a[6] = 30;
  a[7] = 31;
  a[8] = 31;
  a[9] = 30;
  a[10] = 31;
  a[11] = 30;
  int s = 0;
  int b =0;
  for(int i =0; i<m1; i++){
    b+=a[i];
  } 
  b+=d1-1;
  if(y1 == y2) {
     for(int i = 0; i<m2; i++) {
      s+=a[i];
     }
     s+=d2 - 1;
    if(visokosn(y2)) {
    if(m2>2) {
      s+=1;
     }
    }
    s-=b;
    printf("%d", s);
    return 0;
  }
  if(visokosn(y1)) {
    if(m1 > 2) {
      b+=1;
      s = s  +  (366 - b);
    } else {
      s = s + (366 - b);
    }
  }else {
    s = s + (365 - b);
  }
  for(int i = 0; i<m2; i++) {
    s+=a[i];
  }
  s+=d2 - 1;
  

  if(visokosn(y2)) {
    if(m2>2) {
      s+=1;
    }
  }




  for(int i = y1 + 1; i<y2; i++) {
    s+=365;
    if(visokosn(i)) {
      s+=1;
    }
  }
  printf("%d", s);
  return 0;
}