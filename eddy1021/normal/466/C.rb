n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
sum = 0
a.each { |x| sum += x }
if sum % 3 != 0 
  puts 0
  exit
end
sum /= 3
ans, cnt, psum = 0, 0, 0
for x in 0...n-1 do
  psum += a[x]
  ans += cnt if psum == 2 * sum
  cnt += 1   if psum == sum
end
puts ans