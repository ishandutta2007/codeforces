n, k = gets.split.map(&:to_i)
if (n - 1) * n > k * 2
  n.times do |i|
    puts [0, i].join(' ')
  end
else
  puts "no solution"
end