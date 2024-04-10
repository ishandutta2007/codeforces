var n = parseInt(readline());
var a = readline().split(" ");

var i = 0;
var odd = 0;
for (; i < n; ++i)
  if (parseInt(a[i]) % 2 != 0)
    ++odd;

var even = n - odd;
if (even >= odd)
  print(odd);
else
  print(even + Math.floor((odd - even) / 3)); // lol, js divides it as float