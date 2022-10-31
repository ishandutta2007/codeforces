n, m, a, b = gets.chomp.split.map(&:to_i)
ans = a * n
k = 1
while k * m <= n do
  tans = k * b + ( n - k * m ) * a
  ans = tans if tans < ans
  k += 1
end
ans = k * b if k * b < ans
puts ans