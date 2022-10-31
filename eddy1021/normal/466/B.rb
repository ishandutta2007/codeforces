n, a, b = gets.chomp.split.map(&:to_i)
if a * b >= 6 * n
  puts a*b
  puts [a,b].join(' ')
  exit
end
ans, ai, aj = 1000000000 * 1000000000, 1000000000, 1000000000
s = [a,b].min
while s * s <= 12 * n do
  l = ( 6 * n ) / s
  l += 1 if l * s < 6 * n
  ans, ai, aj = l * s, l, s if l*s<ans && l>=a && s>=b
  ans, ai, aj = l * s, s, l if l*s<ans && s>=a && l>=b
  s += 1
end
puts ans
puts [ai, aj].join(' ')